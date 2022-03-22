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


vector<int> f_arr;
void merge(vector<int>& array,int l,int r){
    if(l>=r){
        return ;
    }
    int mid = l+(r-l)/2;
    merge(array,l,mid);
    merge(array,mid+1,r);

    int k = 0;
    int i = l;
    int j = mid+1;

    while(i<=mid && j<=r){
        if(array[i]<array[j]){
            f_arr[k] = array[i];
            i++;
            k++;
        }else{
            f_arr[k] = array[j];
            j++;
            k++;
        }
    }

    while(i<=mid){
        f_arr[k] = array[i];
        k++;
    }

    while(j<=r){
        f_arr[k] = array[j];
        k++;
    }

    for(int i = l,k=0;i<=r;i++,k++){
        array[i] =f_arr[k];
    }

}

int main(){
    vector<int> arr{3,4,5,1,3,76,8};
    int n = arr.size();
    f_arr.resize(n,0);
    merge(arr,0,n-1);
    for(auto c:arr){
        cout<<c<<" ";
    }
    cout<<endl;
}
