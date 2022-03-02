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

class Solution {
public:
    string removeKdigits(string num, int k) {
        //维护一个递增栈
        //当栈顶大于当前的就要删除，不弹出这个，弹出其他的一定比这个大
        stack<char> st;

        for(auto c:num){
            while(!st.empty()&&c<st.top()&&k){
                st.pop();
                k--;
            }
            st.push(c);
        }

        while(k){
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop(); 
        }

        int i;
        for(i=0;i<n;i++){
            if(res[i]!='0'){
                break;
            }
        }

        
    }
};