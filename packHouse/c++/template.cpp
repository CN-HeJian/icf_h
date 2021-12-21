//function template
#include <iostream>
using namespace std;

bool compare(const string &v1,const string &v2){
    return v1<v2;
}

bool compare(const double &v1,const double& v2){
    return v1<v2;
}

//function template
template<typename T>
int compare(const T&v1,const T&v2){
    return v1<v2;
}
  


template <typename T>
T foo(T* p){
    T tmp = *p;
    return tmp;
}

template <typename T,typename U>
void cal(const T&,const U&){

}


template <typename T>
class stack{
    private:
        std::vector<T> elems;
    public:
        void push(T const& elelm);
        void pop();
        T const & top() const;
        bool empty() const{
            return elems.empty();
        }
};

template <typename T>
void stack<T>::push(const T &elem){
    elems.push_back(elem);
}


