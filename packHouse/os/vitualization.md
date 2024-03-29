**1、进程？**

- 程序是静态的、进程是动态运行的程序、进程==状态机
- 进程管理：状态机的创建、管理、销毁

**2、创建进程：fork()**

- 理解fork()函数的返回值

  - ```c++
    int a = fork();
    int b = fork();
    int c = fork();
    cout<<"a"<<a<<"b"<<b<<"c"<<c<<endl;
    ```

  - ```c++
    for(int i=0;i<2;i++){
    	printf("hello\n");
    }
    ```

  - ```c++
    :(){:|:&};://fork bomb
    ```

- 多线程执行fork时会发生什么？

  - fork的创始人没有考虑线程

**3、状态机管理：替换状态机**

- 将当前运行的状态机重置位另一个程序的初始状态

- ```c++
  int execve(const char *filename,char *const argv,char *const envp)
  ```

  - 执行名为filename的程序
  - 允许对新状态机设置参数argv(v)和环境变量envp(e)

**4、销毁状态机：_exit()**

- 销毁当前状态机，并允许有一个返回值

- 子进程会通知父进程

- 多版本的退出

  ```c++
  exit(0);//是_exit(0)的一种封装
  _exit(0);//直接退出，结束进程
  syscall(SYS_exit,0);//结束线程，但不结束进程里的其他线程
  ```

**5、进程需要保障什么？**

- 怎么保证程序不能执行受到操作系统限制的指令
  - 用户模式与内核模式的切换
- 如何实现进程的切换	
  - 上下文切换，进程切换时动作
  - 内核栈，进程对应的数据结构

**6、文件描述符**

- 文件描述符的理解

  ```c++
  int main(){
  	int fd = dup(1);//找到一个指针拷贝原来的位置
  	freopen("output.txt","w",stdout);//标准输出重定向到txt
  	printf("hello\n");
  	fclose(stdout);//关闭标准输出
  	freopen("/dev/null","w",stdout);//指定一个合法的文件
  	dup2(fd,1);//将左边复制给右边
  	close(fd);//关闭原来的
  	printf("world\n");
  }
  ```

- fork()时进程的所有文件描述符都会被子进程继承，父子进程同时写文件，会不会被覆盖，后面会介绍

  ```c++
  fork-printf.c
  ```

- fork应用

  - 跳过初始化
    - Java Virtual Machine 初始化设计大量的类加载，一次加载，全员使用
  - 实现”备份“的容错
    - 定期给程序做备份性质的快照，fork之后在原地停留，主进程crash之后，启动快照重新执行
  - A fork() in the road
    - fork线程不安全
    - fork比较慢

**7、地址空间的抽象**

- 为什么会需要地址空间的抽象？
  - 早期计算机价格高，需要计算机能执行更多的程序、出现了分时系统。
  - 时分共享首先是让进程单独占用全部内存运行一小段时间，停止之后将它的状态信息保存在磁盘上，加载其他进程的状态信息，再运行一段时间，但是内存增加之后，保存全部的内存信息保存到磁盘上就太慢了，解决办法就是将分区存储进程的所有信息。
  - 多个程序保存在同一个磁盘区间中，出现了新的问题，不允许其他进程对当前进程所拥有的内存区间进行修改。
- 地址空间
  - 操作系统提供一个易用(easy to use)的物理内存抽象，这个抽象被叫做地址空间(address space)，是运行的程序看到的系统中的内存。
  - 虚拟地址系统负责为程序提供一个巨大的、稀疏的、私有的地址空间假象。包括代码、堆、栈。
- 虚拟内存的目标
  - 透明：让应用程序不认为自己的地址空间被虚拟化了
  - 效率：保证程序的运行效率不受到影响，另外不需要很大内存支持虚拟化的实现
  - 保护：每个进程都应该在自己的独立环境中运行，避免出错以及恶意进程的影响
  - 用户获取到的地址都是虚拟地址空间，操作系统以及硬件将虚拟地址映射为真实的物理地址

**8、内存管理----分配内存空间以及管理内存空间是构建健壮软件系统的基础**

- 内存类型:堆和栈

  ```
  void func(){
  	int* x = int* malloc(sizeof(int));
  }
  ```

- `malloc()`调用
  - `sizeof()`因此被认为是一个操作符，在编译期间已经知道是多大，函数调用是在程序执行的时候才会调用
  - 返回的是一个指向void类型的指针，通常使用强制转换
  - 为一个字符串申请空间记得需要给字符串结束符号留出空间
- 常见错误
  - 忘记分配内存
  - 没有分配足够的内存
  - 忘记初始化分配的内存
  - 忘记释放内存
  - 在用完之前释放内存呢
  - 反复释放内存
  - 错误使用free()
- 长时间运行的程序一定要注意内存的释放，短期运行不会出现很大的问题

**9、机制---地址转换**

- 目标是高效和控制
  - 高效通过硬件来实现,通过硬件将虚拟地址转换为实际对应的物理地址
  - 控制则需要操作系统在关键位置的介入,设置好硬件,以便完成正确的地址转换

- 动态重定位(dynamic relocation)
  - 每个cpu需要有两个硬件寄存器:基址寄存器和界限寄存器
  - cpu中负责地址转换的部分统称为内存管理单元(MMU)
  - 由于一个cpu只有一个基址寄存器和一个界限寄存器,上下文切换时,必须将当前基址和界限寄存器中的内容保存在内存中

- 内部碎片
  - 已经分配的内存单元内部有未使用的空间
  - 由于假设将物理地址设置为了槽块,所以会存在比较多的内存碎片,因此引入了分段的概念

**10、分段**

- 

**11、空闲空间管理**

- 内部碎片和外部碎片
  - 内部碎片就是已经分配出去(能明确指出属于哪个进程)却不能被利用的内存空间	
  - 外部碎片指的是还没有被分配出去，但由于太小无法分配给申请内存空间的新进程的内存空闲区域
- 内存分配方法
- 内存回收办法

**12、虚拟内存**

- 进程虚拟地址空间的分配

  |    进程虚拟地址空间    |         备注          |
  | :--------------------: | :-------------------: |
  |      kernal space      | 0xFFFFFFFF-0xC0000000 |
  |  命令行参数和环境变量  |                       |
  |           栈           |       自顶向下        |
  | 共享库的存储器映射区域 |                       |
  |           堆           |       自底向上        |
  |        读/写段         |         .bss          |
  |        读/写段         |         .data         |
  |         只读段         | .init、.txt、.rodata  |
  |        预留空间        |       不可读写        |

  

