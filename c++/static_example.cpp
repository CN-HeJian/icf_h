#include <iostream>
#include <string>
#include <vector>
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




class Student{
    public:
        Student(string pszName);
        ~Student();
    public: 
        static void PrintfAllStudents();
    private:
        string name;
        Student* prev;
        Student* next;
        static Student*m_head;
};

Student::Student(string _name){
    name  = _name;
    //insert to head
    this->next = m_head;
    this->prev = nullptr;
    if(m_head!=nullptr){
        m_head->prev = this;
    }
    m_head = this;
}

Student::~Student(){
    if(this==m_head){
        m_head = this->next;
    }else{
        this->prev->next = this->next;
        this->next->prev = this->prev;
    }
}

void Student::PrintfAllStudents(){
    for(Student*p = m_head;p!=nullptr;p=p->next){
        cout<<p->name<<endl;
    }
}

Student* Student::m_head = NULL;

int main(){
    //call by class name
    Account::set_rate(0.5);   
    //call by obj
    Account a;
    a.set_rate(0.6);

    Student studentA("AAA");
    Student studentB("BBB");
    Student studentC("CCC");
    Student studentD("DDD");
    Student student("MoreWindows");

    Student::PrintfAllStudents();
}

//static non this* 因此不能访问非静态成员，非静态成员函数可以调用静态成员函数
//c++中，需要数据为整个类而非某个对象服务，同时又力求不破坏类的封装性，要求成员隐藏在类的内部，对外不可见时，定义为静态数据
//DATA段存放初始化的全局变量和静态变量、BSS段存放未初始化的全局变量和静态变量
