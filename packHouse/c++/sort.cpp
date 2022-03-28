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

/*冒泡排序
稳定
最好情况：O(N)
最坏情况：O(N^2)
平均情况：O(N^2)
*/
#include <bits/stdc++.h>
using namespace std;

void sort(vector<int>& arr){
    int n = arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(auto c:arr){
        cout<<c<<" ";
    }
    cout<<endl;
}

//快速排序
//不稳定的:为什么不是稳定的？
//最好:N*logN
//最坏:N^2
//平均:N*logN
void quickSort(vector<int>& arr,int l,int r){
    if(l>=r){
        return ;
    }
    int x = arr[l];
    int i = l-1;
    int j = r+1;

    while(i<j){
        do{
            i++;
        }while(arr[i]<x);
        do{
            j--;
        }while(arr[j]>x);
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }

    quickSort(arr,l,j);
    quickSort(arr,j+1,r);
}

//归并排序
//最好、最坏都是logN
vector<int> f_arr;
void merge(vector<int>& arr,int l,int r){
       if(l>=r){
        return ;
    }
    int mid = (l+r) >>1;
    merge(arr,l,mid);
    merge(arr,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(arr[i]<=arr[j]){
            f_arr[k] = arr[i];
            i++;
            k++;
        }else{
            f_arr[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        f_arr[k++] = arr[i++];
    }
    while(j<=r){
        f_arr[k++] = arr[j++];
    }
    for(int i=l,j=0;i<=r&&j<k;i++,j++){
        arr[i] = f_arr[j];
    }
}

//直接插入排序思想是什么？
void insert(vector<int>&arr){
    for(int i=0;i<arr.size();i++){
        int temp = arr[i];
        //开始从0比较
        for(int j=0;j<i;j++){
            //发现了第一个小于的元素
            if(temp<arr[j]){
                //往后面移动
                for(int k=i-1;k>=j;k--){
                    arr[k+1] = arr[k];
                }
                arr[j] = temp;
                break;
            }
        }
    }
}

int main(){
    vector<int> arr{2,3,4,6,1,5,3,9};
    int n = arr.size();

    //冒泡
    //sort(arr);

    //快排
    // quickSort(arr,0,arr.size()-1);
    // for(auto c:arr){
    //     cout<<c<<" ";
    // }
    // cout<<endl;

    //归并排序
    // f_arr.resize(n,0);
    // merge(arr,0,n-1);
    // for(auto c:arr){
    //     cout<<c<<" ";
    // }
    // cout<<endl;

    //插入排序
    insert(arr);
}
