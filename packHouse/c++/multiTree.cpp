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

//多叉树
#include <bits/stdc++.h>

using namespace std;

int res = 0;

struct Node{
    int val;
    vector<Node*> child;
    Node(int _val):val(_val),child(){}
};


void dfs(Node* r,int cur_depth){
    if(r->child.size()==0){
        res = max(res,cur_depth);
    }
    for(int i=0;i<r->child.size();i++){
        dfs(r->child[i],cur_depth+1);
    }
}

int main(){
    Node *root = new Node(-1);
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);

    root->child.push_back(node1);
    root->child.push_back(node2);
    root->child.push_back(node3);

    dfs(root,1);

    cout<<"height is: "<<res<<endl;
}
