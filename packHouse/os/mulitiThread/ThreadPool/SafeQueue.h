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
#include <iostream>
#include <queue>
#include <mutex>
using namespace std;


template <typename T>
class SafeQueue{
private:
    std::queue<T> m_queue;
    std::mutex m_mutex;
public:
    SafeQueue(){}
    SafeQueue(SafeQueue &&other){}
    ~SafeQueue(){}  

    bool empty(){
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.empty();
    }

    int size(){
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    void enqueue(T&t){
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.emplace(t);
    }

    bool dequeue(T&t){
        std::unique_lock<std::mutex> lock(m_mutex);
        if(m_queue.empty()){
            return false;
        }
        t = std::move(m_queue.front());
        m_queue.pop();
        return true;
    }

};