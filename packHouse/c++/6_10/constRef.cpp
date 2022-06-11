#include <iostream>
using namespace std;

// void func(const int& a){

// }

void func(const int a){

}

void func(int && a){
    cout<<"right ref"<<endl;
}

int main(){
    int a = 0;
    //func(a);
    func(6);
}