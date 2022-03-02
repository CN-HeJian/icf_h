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
#include <mutex>
#include <queue>
using namespace std;


template<typename T>
class SafeQueue{

private:
    queue<T> m_q;
    mutex m_mutex;
public:
    int size(){
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_q.size();
    }

    bool empty(){
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_q.size()==0;
    }

    void enque(T &t){ 
        std::unique_lock<std::mutex> lock(m_mutex);
        m_q.push(t);
    }

    bool dequeue(T &t){
        std::unique_lock<std::mutex> lock(m_mutex);

        if(m_q.empty()){
            return false;
        }

        t = std::move(m_q.front());
        m_q.pop();
        return true;
    }
};