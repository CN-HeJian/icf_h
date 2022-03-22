//美团面试题
#include <bits/stdc++.h>
using namespace std;

int co = 0;
mutex m_mutex;
condition_variable m_cv;
int flag = 0;

void printOdd(){
   unique_lock<mutex> lock(m_mutex);
   while(co<100){
       while(flag!=0){
           m_cv.wait(lock);
       }
       cout<<co<<endl;
       flag = 1;
       co++;
       m_cv.notify_all();
   }
}

void printEv(){
    unique_lock<mutex> lock(m_mutex);
     while(co<100){
       while(flag!=1){
            m_cv.wait(lock);
       }
       std::cout<<co<<endl;
       flag = 0;
       co++;
       m_cv.notify_all();
   }
}

int main(){
    thread th1(printOdd);
    thread th2(printEv);
    th1.join();
    th2.join();
    return 0;
}
