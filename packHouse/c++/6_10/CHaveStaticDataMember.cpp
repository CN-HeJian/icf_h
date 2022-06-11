#include "CHaveStaticDataMember.h"

#include <iostream>
using namespace std;

int Duplicate(int m){
    cout<<"duplicate: "<<m<<std::endl;
    return 2*m;
}

int CHaveStaticDataMember::m_iStaticInitial = 5;

//main 函数运行之前初始化
int CHaveStaticDataMember::m_iDynInitial = Duplicate(3);	


int main(){
    std::cout<<"main begin"<<std::endl;
    static int key = 0;
    //main 函数运行之后初始化
    static int val = Duplicate(5); 
    std::cout<<"main end"<<std::endl;
    return 0;
}
