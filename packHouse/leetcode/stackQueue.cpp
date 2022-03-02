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


class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        st1.push_back();
    }
    
    int pop() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        if(st2.empty()){
            return -1;
        }      
        int t = st2.top();
        st2.pop();
        return t;
    }
    
    int peek() {
        if(st2.empty()){
            while(!st1.empty()){
                st2.push(st1.top());
                st1.pop();
            }
        }
        if(st2.empty()){
            return -1;
        }      
        int t = st2.top();
        return t;
    }
    
    bool empty() {
        return st1.empty()&&st2.empty();
    }

private:
//使用栈来模拟队列
    stack<int> st1;
    stack<int> st2;
};

//栈新进后出、队列先进先出
//使用栈来实现队列