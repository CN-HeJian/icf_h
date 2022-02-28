// Copyright 2021 icf
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.


// https://zhuanlan.zhihu.com/p/335994370

// const 左值引用可以指向右值,普通的左值引用不允许
// const int& ref = 5;

// 右值引用专门为右值而生，可以指向右值，不能指向左值
// 右值引用可以修改右值
// int &&ref_a_right = 5
// ref_right = 6

//move() 不是移动的作用，而是将左值强制转换为右值

//被声明出的左值和右值都是左值
//右值引用既可以是左值也可以是右值，如果有名称则为左值，否则为右值

//深拷贝构造函数、深拷贝赋值函数
//拷贝构造函数以及赋值运算符重载已经通过左值引用来避免一次多余的拷贝了



#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class A{
public:
    //构造函数
    A():ptr_(new int(100)){
        cout<<"construct ..."<<endl;
    }

    //拷贝构造函数
    A(const A& p){
        cout<<"copy construct ..."<<endl;
        ptr_ = new int();
        memcpy(ptr_,p.ptr_,sizeof(int));
    }

    //移动构造函数
    A(A&& p){
        std::cout<<"move construct ..."<<endl;
        ptr_ = p.ptr_;
        p.ptr_ = nullptr;
    }


    //析构函数
    ~A(){
        cout<<"deconstruct ..."<<endl;
        if(ptr_){
            delete ptr_;
            ptr_ = nullptr;
        }
    }

    //赋值运算符重载符号
    A& operator=(const A &p){
        cout<<"a operator= ..."<<endl;
        return *this;
    }

    //
    int* getVal() {
        return ptr_;
    }

private:
    int *ptr_;
};


void fun(const A&  b){
    //A c=b;
    ///cout<<b.getVal()<<endl;
}

// void fun(A&& b){
//     cout<<"right ref"<<endl;
//     //cout<<b.getVal()<<endl;
// }

int main(int argc, char *argv[]){
    std::vector<A> vec;
    vec.push_back(A());
    cout<<"------"<<endl;
    // A c;
    // fun(c);
    // cout<<"------"<<endl;
    fun(A());
    // cout<<"------"<<endl;
}


