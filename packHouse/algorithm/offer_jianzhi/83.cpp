#include <bits/stdc++.h>
using namespace std;


vector<int> nums = {1,2,3};
vector<vector<int>> res;
vector<int> path;

int n = nums.size();
vector<int> visited(n,false);

void dfs(vector<int>&path){
    if(path.size()==n){
        res.push_back(path);
        return ;
    }
    
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            visited[i] = true;
            path.push_back(nums[i]);
            dfs(path);
            path.pop_back();
            visited[i] = false;
        }
    }
    
}


int main(){
    dfs(path);
    
    for(auto c:res){
        for(auto d:c){
            cout<<d<<" ";
        }
        cout<<endl;
    }
}
