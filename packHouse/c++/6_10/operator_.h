//
// Created by HiJa_En on 2022/6/10.
//

#ifndef DEMO_PRACTICE_OPERATOR__H
#define DEMO_PRACTICE_OPERATOR__H

#include <string>
#include <iostream>

class operator_ {
public:
    operator_() = default;
public:
    void add(std::string key,int value);
    void add(int value,std::string key);
};


#endif //DEMO_PRACTICE_OPERATOR__H
