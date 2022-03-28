#include <iostream>
using namespace std;
#include <bits/stdc++.h>

vector<vector<int>> res;
vector<int> nums = {1,2,3};
vector<int> path;
int n = nums.size();

void dfs(vector<int>& path,int index){
    if(index==n){
        res.push_back(path);
        return ;
    }
    dfs(path,index+1);
    path.push_back(nums[index]);
    dfs(path,index+1);
    path.pop_back();
}

void task(vector<int>&nums){
    dfs(path,0);
    for(auto c: res){
        for(auto d:c){
            cout<<d<<" ";
        }
        cout<<endl;
    }
}

int main(void){
    task(nums);
}
