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

std::mutex mtx;
std::condition_variable cond;
bool ready = false;

void work(int id){
    std::unique_lock<mutex> lck(mtx);
    while(!ready)
        cond.wait(lck);  //线程被阻塞、该函数会自动调用lck.unlock()来解锁
    std::cout<<"thrad "<<id<<endl;
}

void go(){
    std::unique_lock<mutex> lck(mtx);
    ready = true;
    cond.notify_one();
}

int main(){
    std::thread threads[10];
    for(int i=0;i<10;i++){
        threads[i] = std::thread(work,i);
    }
    std::cout<<"10 threads ready to race..."<<std::endl;
    for(int i=0;i<5;i++){
        go();
    }
    for(auto &th:threads){
        th.join();
    }
    return 0;
}
