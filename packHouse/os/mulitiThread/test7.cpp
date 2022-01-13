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

//https://zhuanlan.zhihu.com/p/93327156
//https://blog.csdn.net/sinat_18811413/article/details/104099587

#include <iostream>
#include <functional>
#include <thread>
#include <future>
#include <unistd.h>

using namespace std;

void waitForMilkTea(future<int>& f_notice){
    int notice = f_notice.get();
    std::cout<<"get milk have finished"<<std::endl;
}

void makeMilkTea(promise<int>& p_notice){
    cout<<"milk maked"<<std::endl;
    sleep(10);
    p_notice.set_value(1);
}

int main(){
    promise<int> p_notice;
    future<int> f_notice = p_notice.get_future();

    thread Customer(waitForMilkTea,ref(f_notice));
    thread Waiter(makeMilkTea,ref(p_notice));

    Waiter.join();
    Customer.join();
}
