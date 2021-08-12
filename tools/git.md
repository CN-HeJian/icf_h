### 1、git

##### 1、退回某次提交

```shell
git log
git revert xxxxx//xx表示信息码
```

### 2、windows terminal

##### 1、创建新文件

```
echo >cpu.h //相当于linux中的touch
```

##### 2、给文件改名字

```
mv cpu.h ass.h
```

### 3、shell

##### 1、定义变量

```shell
>>foo=bar
>>echo $foo
bar
>>foo = bar
bash:command not found:foo
>>echo "hello"
hello
>>echo 'World'
World
>>echo "Value is $foo"
value is bar
>>echo 'Value is $foo'
value is $foo
>>echo "we are in $(pwd)"
we are in /home/icf/Desktop/test
```

##### 2、$_

```
$_ //表示上一次命令输入的参数
mkdir hj
cd $_  
cd hj
//进入hj目录下，上面这两条命令都能达到相同的目的
```

##### 3、！！

```shell
!!记录上一次使用的命令
>>mkdir /mnt/new
permision denied
>>sudo !!
sudo mkdir /mnt/new
//上面两条指令是等价的
```

##### 4、￥？

```shell
>>sudo mkdir /mnt/king
>>cd /mnt
>>rm -rf king
permission denied
>>echo $?  //返回上一条消息的是否出错，也即是上一条命令的返回值
1
>>sudo rm -rf king
>>echo $?
0
```

##### 5、||

```shell
//作为条件判断
>>false || echo "0ops fail"
0ops fail
>>true || echo "Will be not be printed" //运算规则是一样的
>>true || echo "Op2"
Op2
```

##### 6、重定向

```shell
>>cat <(ls -l)
total 4
-rwxrwxrwx 1 icf icf 33 Aug 12 09:48 mcd.sh
>>cat <(ls -l ..)
total 8
drwxr-xr-x 4 icf icf 4096 Aug 11 11:25 second
drwxr-xr-x 4 icf icf 4096 Aug 11 11:25 test
>>cat <(ls -l) <(ls -l ..)//需要注意空格
total 4
-rwxrwxrwx 1 icf icf 33 Aug 12 09:48 mcd.sh
total 8
drwxr-xr-x 4 icf icf 4096 Aug 11 11:25 second
drwxr-xr-x 4 icf icf 4096 Aug 11 11:25 test
```

##### 7、特殊含义

```shell
$$ //shell本身的pid
$?//上一条指令的返回值
$0//shell本身的文件名
$#//添加到shell的参数个数
$*//所有的参数列表
$@//和$*类似
```

##### 8、综合示例

```shell
------------------example.sh----------------------
#! /bin/bash
echo "Staring program at $(date)"
echo "Running program $0 with $# argument with pid $$"

for file in "$@"; do
	grep foobar "$file" > /dev/null 2> /dev/null
	if [[ "$?" -ne 0 ]]; then
	  echo "File $file" does not have any foobar,adding one
	  echo "# foobar" >> "$file"
	fi
done
--------------------cmd----------------------------
>> source example.sh  mcd.sh example.sh 
Staring program at Thu 12 Aug 2021 04:21:02 PM CST
Running program bash with 2 argument with pid 1280
File mcd.sh does not have any foobar,adding one

```

### 4、vim

```shell
>>vim mcd.sh
//i表示插入
	mcd(){
		mkdir -p "$1"
		cd ”$1“
	}
//退出先按ese
	//[:q!]退出且不保存
	//[:wq]保存并退出
//加载文件到source
	source mcd.sh//1
	. mcd.sh//2
//执行定义的函数
	mcd yyds
//-----------------------------------------命令行中的输入-----------------------------
vim mcd.sh
...编辑函数
...mcd(){
...    mkdir -p "$1"
...    cd "$1"
...}
source mcd.sh
mcd test
```



