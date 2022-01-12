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
#include <thread>
#include <string>
#include <condition_variable>

using namespace std;

std::mutex mtx;
std::condition_variable cnd;
bool ready = false;
bool process = false;

string data;

void work(){
    std::unique_lock<mutex> lk(mtx);
    cnd.wait(lk,[]{return ready;});

    std::cout<<"worker thread is processing data"<<std::endl;
    data +="after processing";

    process = true;
    std::cout<<"worker thread signals data processing completed"<<std::endl;

    lk.unlock();
    cnd.notify_one();
}

int main(){
    std::thread worker(work);
    data = "Example data ";

    {
        std::lock_guard<mutex> lk(mtx);
        ready = true;
        std::cout<<"main signals data ready for processing\n";
        cnd.notify_one();
    }
    {
        std::unique_lock<mutex> lk(mtx);
        cnd.wait(lk,[]{return process;});
        std::cout << "Back in main(), data = " << data << '\n';
    }
    worker.join();
    return  0;
}   