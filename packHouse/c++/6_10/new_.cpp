#include <bits/stdc++.h>
using namespace std;


class A{
    public:
        //A(int _val):a(_val){}
        
        A(){}

        ~A(){
            cout<<"delete"<<endl;
        }
    private:
        int a;
};

int main(){
    int* sp = new int[10];
    A* ap = new A[10];

    int  *count = (int*)ap;
    cout<<*count<<endl;

    int d1;
	memcpy(&d1, ap, 4);
    cout<<"d1: "<<d1<<endl;

    delete [] ap;
    
    return 0;
}

