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
    string longestPalindrome(string s) {

        //dp[i][j] 表示i,j之间是否能构成回文串
        int n = s.size();
        string res = 0;
        
        vector<vector<bool>> dp(n+1,vector<bool>(n+1,false));

        for(int i=n;i>0;i--){
            for(int j=i;j<=n;j++){
                if(i==j){
                    dp[i][j] = true;
                }else if(i+1==j){
                    dp[i][j] = s[i-1]==s[j-1];
                }else{
                    if(s[i-1]!=s[j-1]){
                        dp[i][j] = false;
                    }else{
                        dp[i][j] = dp[i+1][j-1];
                    } 
                }
                if(dp[i][j]==true){
                     if(res.size()<j-i+1){
                         res = s.substr(i-1,j-i+1);
                     }
                }
            }
        }

        return res;
    }
};
