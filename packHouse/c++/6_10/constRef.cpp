#include <iostream>
using namespace std;

#include "bits/stdc++.h"

typedef void (*f)(int &&a);

// void func(const int& a){

// }

// void func(const int a){

// }


void rightVal(int && a){
    typedef long long ll;
    ll b =  LONG_LONG_MAX;

    cout<<"right ref b:"<<b<<endl;
}

int main(){
    f func = rightVal;
    int a = 0;
    //func(a);
    func(6);
}