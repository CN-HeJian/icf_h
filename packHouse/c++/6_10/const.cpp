//
// Created by HiJa_En on 2022/6/10.
//
#include <bits/stdc++.h>
using namespace std;

const int globalVal = 5;

int externVal = 8;
extern int externVal;

int main(){
    const int tempVal = 8;

    //error---segmentation fault
    int* gp = (int*)&globalVal;
    //*gp = 6;

    //
    int* tp = (int*)&tempVal;
    *tp = 8;
    cout<<"after: "<<tempVal<<endl;

    cout<<"externVal: "<<externVal<<endl;

    return 0;
}
