#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int n = 4;
int k = 2;

vector<vector<int>> res;
vector<int> path;
vector<bool> nums(n+1,false);

void dfs(vector<int> &path,int count,int index){
    if(count==k){
        res.push_back(path);
        return ;
    }
    
    for(int i=index;i<=n;i++){
        path.push_back(i);
        dfs(path,count+1,i+1);
        path.pop_back();
    }
   
} 

int main(void){
    dfs(path,0,1);
    
    for(auto c:res){
        for(auto d:c){
            cout<<d<<" ";
        }
        cout<<endl;
    }
    
}
