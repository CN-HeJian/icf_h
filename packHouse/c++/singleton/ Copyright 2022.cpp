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

class A
{

public:
    static A* getInstance();
    static void deleteInstance();

private:
    A(){}
    ~A(){}
    //拷贝赋值
    A(const A&){}
    //拷贝构造
    const A& operator=(const A&){return *this;}; 

private:
    static A *instance;

};

A* A::instance = new A();


A* A::getInstance(){

}

void A::deleteInstance(){

}

