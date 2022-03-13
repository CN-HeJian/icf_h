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

class Solution {
public:
    
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        travel(root);
        return res;
    }


    void travel(TreeNode* root){
        if(!root){
            return ;
        }
        travel(root->left);
        res.push_back(root->val);
        travel(root->right);
    }
};

class Solution {
public:
    vector<int> res;
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        stack<TreeNode*> st;
        
        while(st.size() || root!=nullptr){
            if(root!=null){
                stack.push(root);
                root= root->left;
            }else{
                TreeNode* t = st.top();
                st.pop();
                res.push_back(t->val);
                root = t->right;
            }
        }

        return res;
    }
};

