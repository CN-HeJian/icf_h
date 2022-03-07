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


struct  TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val_):val(val_),left(nullptr),right(nullptr){}
};

//前序递归
vector<int> pre;
void preOrder(TreeNode* root){
    if(!root){
        return ;
    }
    pre.push_back(root->val);
    preOrder(root->left);
    preOrder(root->right);
}

//前序迭代
vector<int> pre_Not;
void  preOrderNotRec(TreeNode* root){
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        auto t = st.top();
        st.pop();
        pre_Not.push_back(t->val);
        if(t->right)
            st.push(t->right);
        if(t->left)
            //注意：此处一定是t节点
            st.push(t->left);
    }
}

//中序递归
vector<int> inorder_array;
void inOrder(TreeNode* root){
    if(!root){
        return ;
    }
    inOrder(root->left);
    inorder_array.push_back(root->val);
    inOrder(root->right);
}

//中序迭代
vector<int> inorderNot_array;
void inOrderNotRec(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* cur = root;
    //栈空间不为空，并且cur不为nullptr
    while(cur||!st.empty()){
        if(cur){
            st.push(cur);
            cur = cur->left;
        }else{
            TreeNode* t  = st.top();
            st.pop();
            inorderNot_array.push_back(t->val);
            cur = t->right;
        }
    }
}

//后续遍历递归
vector<int> back_array;
void backOrder(TreeNode* root){
    if(!root){
        return ;
    }
    backOrder(root->left);
    backOrder(root->right);
    back_array.push_back(root->val);
}

//后续遍历迭代
vector<int> backNotRec_array;
void backOrederNotRec(TreeNode* root){
    //左右中  --->中右左
    stack<TreeNode*> st;
    if(root)
        st.push(root);
    while(!st.empty()){
        TreeNode* t = st.top();
        st.pop();
        backNotRec_array.push_back(t->val);
        if(t->left){
            st.push(t->left);
        }
        if(t->right){
            st.push(t->right);
        }
    }

    //一定要记得reverse
    reverse(backNotRec_array.begin(),backNotRec_array.end());
}   


int main(){
    TreeNode* root = new TreeNode(0);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* node4 = new TreeNode(4);

    root->left = node1;
    root->right = node2;

    node1->left = node3;
    node1->right = nullptr;

    node2->left = node4;
    node2->right = nullptr;

//前序遍历迭代
    preOrder(root);
    cout<<"rec pre:";
    for(auto c:pre){
        cout<<c<<" ";
    }
    cout<<endl;

//前序遍历迭代
    preOrderNotRec(root);
    cout<<"rec iter:";
    for(auto c:pre_Not){
        cout<<c<<" ";
    }
    cout<<endl;

//中序遍历迭代
    inOrder(root);
    cout<<"rec iter:";
    for(auto c:inorder_array){
        cout<<c<<" ";
    }
    cout<<endl;

//中序遍历迭代
    inOrderNotRec(root);
    cout<<"rec iter:";
    for(auto c:inorderNot_array){
        cout<<c<<" ";
    }
    cout<<endl;

//后续遍历递归
    backOrder(root);
    cout<<"rec iter:";
    for(auto c:back_array){
        cout<<c<<" ";
    }
    cout<<endl;

//后续遍历迭代
    backOrederNotRec(root);
    cout<<"rec iter:";
    for(auto c:backNotRec_array){
        cout<<c<<" ";
    }
    cout<<endl;
}
