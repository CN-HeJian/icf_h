#include <iostream>
using namespace std;

#include <bits/stdc++.h>

int n =3;

vector<string> res;
string s_;

void dfs(int left,int right,string path){
    if(left==0 && right==0){
        res.push_back(path);
        return ;
    }
    if(left>0){
        dfs(left-1,right,path+'(');
    }
    if(right>left){
        dfs(left,right-1,path+')');
    }
}

int main(void){
    // Your code here!
    dfs(n,n,"");
    for(auto c:res){
        cout<<c<<" ";
    }
    cout<<endl;
}
