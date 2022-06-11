//
// Created by HiJa_En on 2022/6/10.
//
#include "operator_.h"
#include <iostream>

int main(){
    operator_ opp;
    std::string temp = "a";
    
    opp.add(temp,5);
    opp.add(5,temp);

    return 0;
}