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


//核心点
//1) condition_variable thread mutex 
//2) unique_lock 
//3) cv.wait() cv.notify_all()

#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>

using namespace std;

mutex m_mutex;
condition_variable cv;
int flag=0;

void printA(){
    unique_lock<mutex> lock(m_mutex);
    int count =0;
    for(int i=0;i<10;i++){
        while(flag!=0){
            cv.wait(lock);
        }
        cout<<"a"<<" "<<endl;
        flag =1;
        cv.notify_all();
    }

}

void printB(){
    unique_lock<mutex> lock(m_mutex);
    for(int i=0;i<10;i++){
        while(flag!=1){
            cv.wait(lock);
        }
        cout<<"b"<<" "<<endl;
        flag =2;
        cv.notify_all();
    }
}


void printC(){
    unique_lock<mutex> lock(m_mutex);

    for(int i=0;i<10;i++){
        while(flag!=2){
            cv.wait(lock);
        }
        cout<<"c"<<" "<<endl;
        flag = 0;
        cv.notify_all();
    }
}


int main(){
    thread th1(printA);
    thread th2(printB);
    thread th3(printC);
    
    th1.join();
    th2.join();
    th3.join();
}
