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

#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int _val):val(_val),left(nullptr),right(nullptr){}
};


TreeNode* buildTree(const vector<int>& vec){
    vector<TreeNode*> nodes(vec.size(),nullptr);

    TreeNode* root;
    for(int i=0;i<vec.size();i++){
        TreeNode* cur=nullptr;
        if(vec[i]!=-1){
            cur = new TreeNode(vec[i]);
        }
        nodes[i] = cur;
        if(i==0){
            root = cur;
        }
    }

    for(int i=0;2*i+2<vec.size();i++){
        if(nodes[i]){
            nodes[i]->left = nodes[2*i+1];
            nodes[i]->right = nodes[2*i+2];
        }
    }
    return root;
}


void printTree(TreeNode* root){

    queue<TreeNode*> q;
    if(root)
        q.push(root);
    vector<int> res;

    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* t = q.front();
            q.pop();
            res.push_back(t->val);
            if(t->left){
                q.push(t->left);
            }   
            if(t->right){
                q.push(t->right);
            } 
        }
    }

    for(auto c:res){
        cout<<c<<" ";
    }
    cout<<endl;

}

int main(){
    vector<int> vec={4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8};;

    TreeNode* root = buildTree(vec);

    printTree(root);

}