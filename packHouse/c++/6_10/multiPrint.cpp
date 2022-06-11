//
// Created by HiJa_En on 2022/6/5.
//
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
using namespace std;
int count = 0;

mutex m_mutex;
condition_variable cv;

void printEven(){
    unique_lock<mutex> lock(m_mutex);
    while(count<10){
        while(count%2!=0){
            cv.wait(lock);
        }
        std::cout<<"printEven:"<<count<<std::endl;
        count++;
        cv.notify_all();
    }
}

void printOdd(){
    unique_lock<mutex> lock(m_mutex);
    while(count<10){
        while(count%2!=1){
            cv.wait(lock);
        }
        std::cout<<"printEven:"<<count<<std::endl;
        count++;
        cv.notify_all();
    }
}

int main(){
    thread th1(printEven);
    thread th2(printOdd);
    th1.join();
    th2.join();
    return 0;
}

