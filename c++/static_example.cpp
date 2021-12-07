#include <iostream>
using namespace std;

class Account{
    public:
        //declaration
        static double m_rate;
        static void set_rate(const double&x){
            m_rate = x;
        }
};

//define 
double Account::m_rate = 0.8;

int main(){
    //call by class name
    Account::set_rate(0.5);   
    //call by obj
    Account a;
    a.set_rate(0.6);
}
