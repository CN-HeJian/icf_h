#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std::placeholders;
using namespace std;

bool islessThanOrEqualTo6(const string&s,string::size_type sz){
    return s.size()<=sz;
}

bool chekc_size(string const &str,size_t sz){
    return str.size()<sz;
}


int main(){
    std::vector<string> author{"Mosophy","Pes8szy","Queequeg90"};
    cout<<count_if(author.cbegin(),author.cend(),bind(islessThanOrEqualTo6,_1,6))<<endl;

    vector<int> vec{0,1,2,3,4,5,6};
    string str = "hel";
    auto res = find_if(vec.cbegin(),vec.cend(),bind(chekc_size,str,std::placeholders::_1));
    if(res!=vec.end()){
        cout<<*res<<endl;
    }else{
        cout<<"not found"<<endl;
    }
    return 0;
}

