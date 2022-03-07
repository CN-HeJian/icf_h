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

//生产者消费者模型

#include <bits/stdc++.h>
using namespace std;

mutex mtx;
//可以生产的条件变量,可以消费的条件变量
condition_variable can_produce,can_consume;
//资源队列
queue<int> resource;
//最多的资源
const int max_size = 10;

//消费者
void consumer(){
    while(true){
        unique_lock<mutex> lock(mtx);
        while(resource.size()==0){
            can_consume.wait(lock);
        }
        int cur_source = resource.front();
        resource.pop();
        cout<<"consumer "<<this_thread::get_id()<< " consume resource:"<<cur_source<<",size: "<<resource.size()<<endl;
        can_produce.notify_all();
    }
}

//生产者
void product(){
    while(true){
        unique_lock<mutex> lock(mtx);
        while(resource.size()==max_size){
            can_produce.wait(lock);
        }
        int cur_source = rand();
        resource.push(cur_source);
        cout<<"produter "<<this_thread::get_id()<<" produce resource:"<<cur_source<<",size: "<<resource.size()<<endl;
        can_consume.notify_all();
    }
}


int main(){
    vector<thread> consumers(5);
    vector<thread> productors(5);


    for(int i=0;i<5;i++){
        consumers[i] = thread(consumer);
        productors[i] = thread(product);
    }

    for(int i=0;i<5;i++){
        consumers[i].join();
        productors[i].join();
    }

    return 0;
}