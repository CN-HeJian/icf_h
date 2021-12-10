// Copyright 2021 icf
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
//     http://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <iostream>
#include <vector>
#include <memory>
#include <initializer_list>
using namespace std;

class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> i1);
    size_type size() const {
        return data->size();
    }
    bool empty()const {
        return data->empty();
    }
    void push_back(const std::string &t){
        data->push_back(t);
    }
    void pop_back();
    std::string &front();
    std::string &back();
    const std::string& front() const;
    const std::string& back() const;
    std::shared_ptr<std::vector<string>>& getData(){
        return data;
    }
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i,const std::string &msg) const;
};

StrBlob::StrBlob():data(make_shared<vector<string>>()){}

StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){}

void StrBlob::check(size_type i,const string &msg)const{
    if(i>=data->size()){
        throw out_of_range(msg);
    }
}

string& StrBlob::front(){
    check(0,"front on empty StrBlob");
    return data->front();
}

string& StrBlob::back(){
    check(0,"back on empty StrBlob");
    return data->back();
}

const std::string& StrBlob::front() const{
    check(0,"front on empty StrBlob");
    return data->front();
}

const std::string& StrBlob::back() const{
    check(0,"back on empty StrBlob");
    return data->back();
}


void StrBlob::pop_back(){
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}



auto populate(vector<int>* vec){
    for(int i;std::cout<<"Pls Enter:\n",std::cin>>i;vec->push_back(i));
    return vec;
}

auto populate(std::shared_ptr<vector<int>> vect){
    for(int i;std::cout<<"Pls Enter:\n",std::cin>>i;vect->push_back(i));
    return vect;
}




auto printf(vector<int>* vec)->std::ostream&{
    for(auto i:*vec){
        std::cout<<i<<" ";
    }   
    std::cout<<endl;
    return std::cout;
}

auto printf(std::shared_ptr<vector<int>> &vect)->std::ostream&{
    for(auto i:*vect){
        std::cout<<i<<" ";
    }
    std::cout<<endl;
    return std::cout;
}


int main(){
    StrBlob b1;
    {
        StrBlob b2 = {"a","an","the"};
        b1 = b2;
        b2.push_back("about");
        //cout<<"b1 count: "<<b1.data.use_count()<<endl;
        //cout<<"b2 count: "<<b2.data.use_count()<<endl;

        cout<<"b1 count: "<<b1.getData().use_count()<<endl;
        cout<<"b2 count: "<<b2.getData().use_count()<<endl;
    }
    //cout<<"b1 count: "<<b1.data.use_count()<<endl;
    cout<<"b1 count: "<<b1.getData().use_count()<<endl;

    const StrBlob csb{"hello","world","pezzy"};
    StrBlob sb{"hello","world","Mooophy"};

    std::cout<<csb.front()<<" "<<csb.back()<<endl;
    sb.back() = "pezy";
    std::cout<<sb.front()<<" "<<sb.back()<<endl; 

    const int* p = new const int(2333);
    delete p;
    p = nullptr;
    int*p2 = new int(1122);
    p = p2;
    cout<<"*p: "<<*p<<endl;
    delete p;
    p = nullptr;
    //delete p2; //double free detected in tcache 2
    //p2 = nullptr;

    const int *pci  = new const int(1024);
    delete pci; //dangling point [空悬指针]
    pci=nullptr;

    //12.6
    vector<int>* vec = new vector<int>();
    populate(vec);
    cout<<"printf cin"<<endl;
    printf(vec);
    delete vec; 

    //12.7
    std::shared_ptr<vector<int>> vect(new vector<int>());
    populate(vect);
    cout<<"smart_point: print cin:"<<endl;
    printf(vec);

    //12.8


    //12.9


    return 0;
}