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

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size()-1;
        int n2 = version2.size()-1;
        int i=0,j=0;
    
        while(i<=n1 || j<=n2){
            int temp1 = 0;
            int temp2 = 0;
            if(i<=n1){
                while(i<=n1&&version1[i]!='.'){
                    temp1 = temp1*10+version1[i]-'0';
                    i++;
                }
                i++;
            }
            if(j<=n2){
               while(j<=n2&&version2[j]!='.'){
                    temp2 = temp2*10+version2[j]-'0';
                    j++;
                }
                j++;
            }
            if(temp1<temp2){
                return 1;
            }
            if(temp1>temp2){
                return -1;
            }
        }
        return 0;
    }
};