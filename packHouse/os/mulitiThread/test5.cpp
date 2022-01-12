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

#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>
using namespace std;


struct Box{
    explicit Box(int num):num_(num){};

    mutex m;
    int num_;
};


void work(Box & from,Box &to ,int num){

    std::unique_lock<std::mutex> lock1(from.m,std::defer_lock);
    std::unique_lock<std::mutex> lock2(to.m,std::defer_lock);

    std::lock(lock1,lock2);

    from.num_ -= num;
    to.num_ += num;

    std::cout<<"from.num_: "<<from.num_<<std::endl;
    std::cout<<"to.num_: "<<to.num_<<std::endl;
}

int main(){
    Box a(100);
    Box b(50);

    std::thread t1(work,ref(a),ref(b),50);
    std::thread t2(work,ref(a),ref(b),30);

    t1.join();
    t2.join();

    std::cout<<"a.num_: "<<a.num_<<std::endl;
    std::cout<<"b.num_: "<<b.num_<<std::endl;

}

