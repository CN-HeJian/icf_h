// Copyright 2022 icf
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

#include <bits/stdc++.h>

using namespace std;

class LRU{
public:
    LRU(int _cap):cap(_cap){}

    int get(int key){
        if(map.find(key)==map.end()){
            //没有查找到
            return -1;    
        }
        //找到在list中迭代器的位置
        auto key_value = *map[key];
        //删除缓存里面的东西
        cache.erase(map[key]);
        //链表前端插入key_value
        cache.emplace_front(key_value);
        //重新映射位置
        map[key] = cache.begin();
        //返回获取到的值
        return key_value.second;
    }

    void put(int key,int value){
        //如果在
        if(map.find(key)!=map.end()){
            auto key_value = *map[key];
            cache.erase(map[key]);
        }else{
            //不在则需要考虑容量
            if(cache.size()>=cap){
                map.erase(cache.back().first);
                cache.pop_back();
            }
        }
        cache.emplace_front(make_pair(key,value));
        map[key] = cache.begin();
    }

private:
    int cap;
    list<pair<int,int>> cache;
    unordered_map<int,list<pair<int,int>>::iterator> map;
};
