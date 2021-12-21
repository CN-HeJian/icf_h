#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    //intro to lambda
    auto g = []()->int{return 42;};
    cout<<"intro to lambda: "<<g()<<endl;

    //pass parameter to lambda
    auto f = [] (const string s1,const string s2)->string{return s1+" "+s2;};
    cout<<"pass parameter to lambda："<<f("hello","world")<<endl;

    //use capture list
    int sz=1;
    auto h = [sz](const string s)->bool{ return s.size()<sz;};
    cout<<"using capture list： "<<h("hello")<<endl;

    //value capture
    size_t v1 = 4;
    auto m = [v1]()->size_t{return v1;};
    v1 = 0;
    cout<<"value capture: "<<m()<<endl;

    //refer capture
    v1 = 2;
    auto n = [&v1]()->size_t{return ++v1;};
    cout<<"refer capture: "<<n()<<endl;

    //implicit refer capture
    v1 = 5;
    auto k = [&]()->size_t{return ++v1;};
    v1++;
    cout<<"implicit refer capture: "<<k()<<endl;

    //implicit value capture
    v1 = 5;
    auto p= [=]()->size_t{return v1;};
    v1++;
    cout<<"implicit value capture: "<<p()<<endl;

    //mutable lambda,passing for a value does not change its value
    v1 = 7;
    auto q = [v1]()mutable->size_t{return ++v1;};
    v1++;
    cout<<"mutable value capture "<<q()<<" "<<v1<<endl;

    //specify the return type
    vector<double> v2 = {-2.2};
    transform(v2.begin(),v2.end(),v2.begin(),[](double i){
        if(i<0)
            return -i;
        else
            return i;
    });
    cout<<"specify the return type "<<v2[0]<<endl;
    
    //homework 10.21
    int i = 10;
    auto v = [&i]()->bool{
        i--;
        return i==0?true:false;
    };
    while(!v()){
        cout<<i<<endl;
    }
}







