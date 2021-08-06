1、tuple类型

2、函数指针

- 函数的类型是由他的返回类型和形参类型共同决定的，与函数名无关

  - `bool （*pf）(const string &,const string &)`--声明一个函数指针

  - 右侧的是形参列表，表示pf指向的是函数，左侧发现函数的返回类型是布尔值

  - 声明了一个函数指针，怎么使用一个函数指针呢？

    - ```
      bool IsEqual(const string& ,const string &);//我们定义的函数
      bool (*pf)(const string &,const string &);//声明的函数指针
      pf = IsEqual;//pf指向的是名为IsEqual的函数
      pf = &IsEqual;//等价的赋值语句，取地址符号是可取的
      pf = nullptr;//函数指针可以赋值为nullptr或者0
      ```

- 指针数组和数组指针
  - int *p1[10]---指针数组
  - int  (*p2)[10]---数组指针
  - 解释：[ ]的优先级别比`*`高，( )的优先级别比[ ]高，p1优先与[10]结合，因此表示一个数组，前面的 int`*`表示int类型的指针，而(*p2)则表示优先与p2优先与`*`结合构成一个指针，int修饰的是10个元素，这儿的数组并没有名字，是一个匿名数组。



