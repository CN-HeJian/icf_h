#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> nums  = {1,1,1};
int n = nums.size();

vector<int> visited(n,false);

vector<vector<int>> res;
vector<int> path;

void dfs(vector<int>& path){
    if(path.size()==n){
        res.push_back(path);
        return ;
    }
    for(int i=0;i<n;i++){
        if(i>0 &&nums[i]==nums[i-1]&&visited[i-1]==false){
            continue;
        }
        if(visited[i]==false){
            path.push_back(nums[i]);
            visited[i] = true;
            dfs(path);
            path.pop_back();
            visited[i] = false;
        }
    }
}


int main(){
    sort(nums.begin(),nums.end());
    dfs(path);
    for(auto c:res){
        for(auto d:c){
            cout<<d<<" ";
        }
        cout<<endl;
    }
}
