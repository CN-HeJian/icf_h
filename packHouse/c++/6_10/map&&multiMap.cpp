//
// Created by HiJa_En on 2022/6/10.
//

#include <iostream>
#include <map>
using namespace std;

template<typename T>
void print(T src) {
    for(auto &c:src){
        cout<<c.first<<" "<<c.second<<endl;
    }
}

int main(){
    map<int,string> mp;
    multimap<int,string> mmp;

    //map 插入相同的key时不会替换这个key对应的value,反而会忽略这条insert
    mp.insert({1,"1"});
    mp.insert({1,"2"});
    print(mp);

    //multimap允许键值是存在重复的！
    mmp.insert({1,"x"});
    mmp.insert({1,"sx"});
    print(mmp);

    //输出当前有多少元素
    cout<<"size of map: "<<mmp.size()<<std::endl;

    //便利所有的元素
    for(auto c:mmp){
        cout<<c.first<<" "<<c.second<<endl;
    }

    //输出某一个key的个数
    cout<<"key count: "<<mmp.count(1)<<endl;
}
