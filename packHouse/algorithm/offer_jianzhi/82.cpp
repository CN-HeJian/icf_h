#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//有重复元素的正整数 nums target
//树层去重

vector<int> candicates = {10,1,2,7,6,1,5};
int n = candicates.size();
int target = 8;
vector<vector<int>> res;
vector<bool> visited(n,false);
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
        if(i>=1&&candicates[i]==candicates[i-1] && visited[i-1]==false){
            continue;
        }
        sum += candicates[i];
        path.push_back(candicates[i]);
        visited[i] = true;
        dfs(path,i+1,sum);
        sum -= candicates[i];
        path.pop_back();
        visited[i] = false;
    }
}
    
int main(){
    sort(candicates.begin(),candicates.end());
    dfs(path,0,0);
    for(auto c:res){
        for(auto d:c){
            cout<<d<<" ";
        }
        cout<<endl;
    }
    return 0;
}
