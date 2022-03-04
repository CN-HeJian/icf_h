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
    vector<int> res;
    string s;
    int length;

    vector<int> splitIntoFibonacci(string num) {
        dfs(0,0,0);
        
    }

    bool dfs(int index,int sum,int pre){
        if(index==length){
            if(res.size()>=3){
                return true;
            }
        }
        long long cur = 0;
        for(int i=0;i<length;i++){
            if(i>index&&s[index]=='0'){
                break;
            }
            cur = cur*10+s[i]-'0';
            if(cur>INT_MAX){
                break;
            }
            if(res.size()>=2){
                if(cur<sum){
                    continue;
                }
                else if( cur>sum){
                    break;
                }
            }
            res.push_back(cur);
            int res = dfs(i+1,pre+cur,cur);
            if(res==true){
                return true;
            }
            res.pop_back();
        }

        return false;
        
    }
};