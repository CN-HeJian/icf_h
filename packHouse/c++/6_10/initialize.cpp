#include <iostream>

using namespace std;


class A{
public:
    A(){}  //没有显示提供其他构造函数才会调用。
    A(const string& str="", int t=0):str(str),t(t){cout<<str<<" "<<t<<endl;}

private:
    string str;
    int t;
};

class C{
public:
    C(){};
    C(const string& str="",int t=0):str(str),t(t){cout<<str<<" "<<t<<endl;}
private:
    string str;
    int t;
};

class B:public A{
public:
    B(){}
    //B():A("123",3),attention("456",3){}
private:
    C attention;
};

int main()
{
    B b;

    return 0;
}
