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
#include <vector>
using namespace std;

void sort(vector<int>&array){
    int cycle = array.size();
    bool flag = true;
    for(int i=0;i<cycle-1&&flag;i++){
        flag =false;
        for(int j=0;j<cycle-1-i;j++){
            if(array[j]>array[j+1]){
                //int temp = array[j];
                array[j] = array[j]^array[j+1];
                array[j+1] = array[j]^array[j+1];
                array[j] = array[j]^array[j+1];
                flag = true;
            }
        }
    }
}

int main(){
    vector<int> array={88,588,46,67,52,29,7};
    sort(array);
    
    for(auto c:array){
        cout<<c<<" ";
    }

    cout<<endl;
}