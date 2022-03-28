#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//无重复元素的正整数 nums target


vector<int> candicates = {2,3,6,7};
int n = candicates.size();
int target = 7;
vector<vector<int>> res;
vector<int> path;

void dfs(vector<int> path,int index,int sum){
    if(sum>target){
        return ;
    }
    if(sum == target){
        res.push_back(path);
        return ;
    }
    for(int i=index;i<n;i++){
        sum += candicates[i];
        path.push_back(candicates[i]);
        dfs(path,i,sum);
        sum -= candicates[i];
        path.pop_back();
    }
}
    
int main(){
    dfs(path,0,0);
    for(auto c:res){
        for(auto d:c){
            cout<<d<<" ";
        }
        cout<<endl;
    }
    return 0;
}   

