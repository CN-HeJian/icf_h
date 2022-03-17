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

// class Singleton{
// public:
//     static Singleton& getInstance(){
//         static Singleton instance;
//         return instance;
//     }
// private:
//     Singleton()=default;
//     Singleton(const Singleton& rhs)=delete;  //禁止使用拷贝构造函数
//     Singleton& operator=(const Singleton& rhs) = delete; //禁止使用拷贝赋值运算符
// };


#include <mutex>
#include <pthread.h>
using namespace std;

class Singleton{
public:
    static Singleton* getInstance();
    static void deleteInstance();
private:
    Singleton(){}
    ~Singleton(){}
    Singleton(const Singleton& rhs)=delete;
    Singleton& operator=(const Singleton rhs)=delete;
    static Singleton* m_instance;
    static mutex m_mutex;
};


Singleton* Singleton::m_instance=nullptr;
mutex m_mutex;


Singleton* Singleton::getInstance(){
    if(m_instance==nullptr){
        unique_lock<mutex> lock(m_mutex);
        if(m_instance==nullptr){
            m_instance = new Singleton();
        }
    }
    return m_instance;
}

void Singleton::deleteInstance(){
    unique_lock<mutex> lock(mutex);
    if(m_instance){
        delete m_instance;
        m_instance = nullptr;
    }
}




