#include <iostream>
using namespace std;

class Vir{
    public:
        Vir(int _value):val(_value){
            std::cout<<"Vir: "<<std::endl;
        }
        virtual void func() = 0;
        virtual void add() = 0;
    private:
        int val;
};

class C{
    public:
        C(){
            std::cout<<"C: "<<std::endl; 
        };
        C(int val_):val(val_){
            std::cout<<"C: "<<std::endl;
        }
    private:
        int val;
};

class v:public Vir{
    public:
        v(int _val):c(),Vir(_val),val(_val){
            std::cout<<"v: "<<std::endl;
        }
        virtual void func(){
            std::cout<<"func"<<std::endl;
        }
        virtual void add(){
            std::cout<<"add"<<std::endl;
        }
    private:
        int val;
        C c;
};

int main(){
    v p(5);
    p.add();
    p.func();
    return 0;
}

//表明调用顺序为:
//  抽象类的构造函数
//  基类构造函数函数
//  类的成员函数的构造函数
//  类的构造函数

/*
Vir: 
C: 
v: 
add
func
*/