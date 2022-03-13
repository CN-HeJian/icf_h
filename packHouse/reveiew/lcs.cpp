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

//最长公共子序列
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        //无聊
        int m = text1.size();
        int n = text2.size();

        vector<vector<int>> dp(m,vector<int>(n,0));

        //dp[i][j] 
        //text1[i-1] == text2[j-1]  dp[i-1][j-1]+1
        //text1[i-1] !=text2[j-1]   max(dp[i-1][j],dp[i][j-1])
        int res = 0;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j]  = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[m][n];


    }
};