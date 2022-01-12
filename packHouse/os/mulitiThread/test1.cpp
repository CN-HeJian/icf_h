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

#include <iostream>
#include <mutex>
#include <condition_variable>
#include <deque>
#include <thread>
#include <memory>
using namespace std;

deque<int> q;
std::mutex mtx;


void product(){
    int count  = 10;
    while(count>0){
        {
            std::unique_lock<std::mutex> locker(mtx);
            q.push_back(count);
            locker.unlock();
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        count--;
    }
}

void cusumer(){
    int data = 0;
    while(data!=1){
        std::unique_lock<std::mutex> locker(mtx);
        if(!q.empty()){
            data = q.back();
            q.pop_back();
            locker.unlock();
            std::cout<<"csusumer got a value from product: "<<data<<std::endl;
        }else{
            locker.unlock();
        }
    }
}

int main(){
    std::thread t1(product);

    std::thread t2(cusumer);

    t1.join();
    t2.join();
    return 0;
}

