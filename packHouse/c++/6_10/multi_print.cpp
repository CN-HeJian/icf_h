//
// Created by HiJa_En on 2022/6/10.
//
#include <bits/stdc++.h>
using namespace std;

mutex m_mutex;
condition_variable cv;
int c = 0;
int flag = 0;

void printA(){
    while(c<100) {
        unique_lock<mutex> lock(m_mutex);
        while (flag == 1) {
            cv.wait(lock);
        }
        cout << "count: " << c << endl;
        flag = 1;
        c++;
        cv.notify_all();
    }
}

void printB(){
    while(c<100) {
        unique_lock<mutex> lock(m_mutex);
        while (flag == 0) {
            cv.wait(lock);
        }
        cout << "count: " << c << endl;
        flag = 0;
        c++;
        cv.notify_all();
    }
}

int main(){
    thread th1(printA);
    thread th2(printB);
    th1.join();
    th2.join();
}