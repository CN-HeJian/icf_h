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

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        //中左右  中右左  左右中


        vector<int> res;
        stack<TreeNode*> st;

        st.push(root);
        
        
        while(!st.empty()){
            
            auto t = st.top();
            st.pop();

            if(!t){
                continue;
            }

            res.push_back(t->val);

            st.push(t->left);
            st.push(t->right);

        }

        reverse(res.begin().res.end());

        return res;
    }
};