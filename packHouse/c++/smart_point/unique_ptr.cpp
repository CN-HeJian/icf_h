// Copyright 2022 icf
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


//参考连接：https://zhuanlan.zhihu.com/p/150555165

//:https://www.bilibili.com/video/BV1nF411H7kd?spm_id_from=333.999.0.0


#include <iostream>
using  namespace std;
#include <bits/stdc++.h>



template<typename T>
class Unique_ptr{
public:
    //默认构造函数
    Unique_ptr(){};
    //构造函数
    Unique_ptr(T* ptr):ptr_(ptr){}
    //默认赋值函数(拷贝构造函数)
    Unique_ptr(const Unique_ptr&)=delete;
    //移动构造函数
    Unique_ptr(Unique_ptr&& rhs){
        ptr_(rhs.release());
    }

    ~Unique_ptr(){
        delete ptr_;
    }
    
    T* get(){
        return ptr_;
    }
    T* release(){
        return  std::exchange(ptr_,nullptr);//先返回ptr_,然后再将ptr_设置为空
    }
    void reset(T* ptr){
        delete std::exchange(ptr_,nullptr);
    }
    void swap(Unique_ptr& rhs){
        std::swap(rhs,this->ptr_);
    }

    //赋值符号
    Unique_ptr& operator=(const Unique_ptr& )=delete;
    //移动赋值
    Unique_ptr& operator=(Unique_ptr &&rhs){
        reset(rhs.release());
        return *this;
    }
    
    operator bool(){
        return static_cast<bool>(ptr_);
    }

    T& operator*(){
        return *ptr_;
    }
    T* operator->(){
        return ptr_;
    }

private:
    T* ptr_{nullptr};    
};






int main(){
    unique_ptr<int[]> p = make_unique<int[]>(10);
    for(int i=0;i<10;i++){
        p[i] = i*i;
    }
    for(int i=0;i<10;i++){
        cout<<p[i]<<endl;
    }
}

//unique_ptr 指针独占对象
// 拷贝构造函数以及赋值构造函数声明为delete或者private
//只能直接初始化，需要使用explict关键字

