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
#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while(cin>>s){
        int n = s.size();
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1-i;j++){
                if((s[j]>='A'&&s[j]<='Z') && (s[j+1]>='a' && s[j+1]<='z')){
                    swap(s[j],s[j+1]);
                }
            }
        }
        cout<<s<<endl;
    }
}