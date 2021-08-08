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

3、C++中的struct和c语言中的struct

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

