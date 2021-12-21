1、tuple类型

##### 2、函数指针

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

  - 重载(overloading)函数

    - 函数名相同、参数类型或者个数不一样
    - 使用重载函数，上下文必须清晰的确定使用哪个函数 

- 函数指针的形参

  - 将函数作为函数的一个形参，声明的时候两种方式均可以

    ```c++
    #include <iostream>
    using namespace std;
    int m_add(int a,int b){
    	return a+b;
    }
    //第一种方式，第三个参数会自动的转换为指向函数的指针
    int multiAdd(int a,int b,int fnc(int a,int b)){
    	return fnc(a,b);
    }
    //显示的将形参定义成指向函数的指针,两种方式只能使用一个
    //int multiAdd(int a,int b,int (*fnc)(int a,int b)){
    	//return fnc(a,b);
    //}
    int main(){
    	int g = multiAdd(4,6,m_add);
    	cout<<g<<endl;
    }
    ```

  - 由于函数声明太长了，因此使用`decltype`来简化形参

    ```c++
    #include <iostream>
    using namespace std;
    int m_add(int a,int b){
    	cout<<"a+b "<<a+b<<endl;
    }
    //以下几种形式都可以
    typedef decltype(m_add) ft;
    typedef int ft2(int a,int b);
    typedef decltype(m_add)* ft3;
    typedef int (*ft4)(int a,int b);
    //此函数可以中的声明可以换为ft、ft2、ft3、ft4
    int multiAdd(int a,int b,ft2 func){
    	func(a,b);
    }
    int main(){
    	multiAdd(1,4,m_add);
    }
    ```

  - 返回函数指针的应用

    ```C++
    #include "iostream"
    using namespace std;
    #include <string>
    
    int add(int a,int b){
        cout<<"a+b "<<a+b<<endl;
    }
    int dec(int a,int b){
        cout<<"a+b "<<a-b<<endl;
    }
    //定义1
    decltype(add)* getFunc(string type){
        if(type=="add")
            return add;
        else
            return dec;
    }
    //定义2
    auto getFunc2(string type) -> int (*) (int a ,int b){
        if(type=="add")
            return add;
        else
            return dec;
    }
    //定义3
    int (*getFunc3(string type))(int a,int b){
        if(type=="add")
            return add;
        else
            return dec;
    }
    int main(){
        getFunc("add")(3,5);
        getFunc("dec")(3,5);
        getFunc2("add")(3,5);
        getFunc3("add")(5,7);
    }
    ```

- 指针数组和数组指针

  - int *p1[10]---指针数组
  - int  (*p2)[10]---数组指针
  - 解释：[ ]的优先级别比`*`高，( )的优先级别比[ ]高，p1优先与[10]结合，因此表示一个数组，前面的 int`*`表示int类型的指针，而(*p2)则表示优先与p2优先与`*`结合构成一个指针，int修饰的是10个元素，这儿的数组并没有名字，是一个匿名数组。

- 

##### 3、C++中的struct和c语言中的struct

```
c：
struct STUDENT{
	uint64_t age;
};
定义一个对象时需要这样写
struct STUDENT bob;
引入了typedef
typedef struct STUDENT{
	uint64_t age;
}stu_t;
//此时可以少写一个struct 
stu_t bob

c++
在C++中struct和class是一样的
```

##### 4、static关键字

- (面向对象)静态成员变量

c++中的static，静态成员变量在全局数据区分配内存，有本类的所有对象共享，不属于特定的对象，不占用对象的内存，静态数据成员的内存空间既不是在声明类时分配，也不是在创建对象时分配。静态成员变量必须初始化，而且只能在类外进行，否则编译能通过，链接不能通过

- (面向对象)静态成员函数

静态成员函数属于类本身，而不作用于对象，因此它不具有this指针，只能调用类的静态成员函数和静态成员变量，怎么理解呢？因为静态成员函数和静态成员变量在实例化之前就可以访问，因此静态成员不能访问非静态成员

```
static float getAverage();//在类内声明
flaot Student::getAverage()//在类外定义，不需要加上static，只能调用静态成员变量和静态成员函数
Student::getAverage() //调用
```

- (面向过程)静态全局变量

静态全局变量在全局数据区分配内存，未初始化的静态全局变量会自动初始化为0，在声明他的整个文件是可见的，而在文件之外是不可见的

- (面向过程)静态局部变量

每当程序运行到该语句时都会给该局部变量分配栈内存。但随着程序退出函数体，系统就会收回栈内存，局部变量也相应失效。但有时候我们需要在两次调用之间对变量的值进行保存。通常的想法是定义一个全局变量来实现，缺点是变量不受函数控制，给程序的维护带来不便，因此引入静态局部变量。

- (面向过程的)静态成员函数

静态成员函数不能被其他文件所用，其他文件可以定义重名的函数，不会发生冲突

```
static void fn();//声明
void fn()//定义
```

##### 5、union

