# 递归

## 98 二叉搜索树

### 中序遍历

```c++
//迭代写法
class Inorder{
public:
    vector<int> nums;
    vector<int> inorder(TreeNode *root){
        dfs(root);
        return nums;
    }
    void dfs(TreeNode *root){
        //递归终止条件
        if(!root)
            return ;
        //递归
        dfs(root->left);
        res.push_back(root->val);
        dfs(root->right);
    }
};
```

### 自顶向下范围判断法

每一个节点均有一个范围，采用递归的方式，第一个根节点的范围是INT_MIN~INT_MAX

```C++
class Solution{
    public:
	bool isValidBST(TreeNode *root){
        return dfs(root,INT_MIN,INT_MAX);
    }
    bool dfs(TreeNode *root,long long minv,long long maxv){
        if(!root)
       		return true;
        if(root->val < minv || root->val > maxv)
            return false;
        auto left = dfs(root->left,minv,root->val-1ll);
        auto right = dfs(root->right,root->val+1ll,maxv);
        return left && right;
    }
};
```

递归遍历需要遍历所有的节点，仅仅在出现错误的情况下返回，当全部遍历完才会返回true;

## 94 二叉树的中序遍历

### 递归写法

```C++
class Solution {
public:
    vector<int> nums;
    vector<int> inorderTraversal(TreeNode* root) {
        dfs(root);
        return nums;
    }
    void dfs(TreeNode *root){
        if(!root)
            return ;
        dfs(root->left);
        nums.push_back(root->val);
        dfs(root->right);
    }
};
```

### 迭代写法

维护一个栈，每次转移到当前节点引申的最左边，压入数组，然后再考虑右边，如此迭代，只要当前节点不空或者栈不空便一直循环

```C++
class Solution {
public:
    vector<int> nums;
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        auto p = root;
        while(p || stk.size()){
        	while(p){
                stk.push(p);
                p = p->left;
            }   
            nums.push_back(stk.top()->val);
            p = stk.top()->right;
            stk.pop();
        }
        return nums;
    }
};
```

## 101 对称二叉树

### 递归写法

```C++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return dfs(root->left,root->right);
    }
   	bool dfs(TreeNode *left,TreeNode *right){
        if(!left || !right){
            return !left && !right;
        }
        if(left->val != right->val){
        	return false;
        }
        return dfs(left->left,right->right) && dfs(left->right,right->left);
    }
};
```

### 迭代写法

左子树从最左边遍历，右子树从最右边遍历，分别判断每一个是否相等即可

```C++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
		auto r_left = root->left;
        auto r_right = root->right;
       	stack<TreeNode*> l_stk,r_stk;
        while(r_left || r_right || l_stk.size() ||r_stk.size()){
            while(r_left && r_right){
                l_stk.push(r_left);
                r_stk.push(r_right);
                r_left = r_left->left;
                r_right = r_right->right;
            }
            if(r_left || r_right){
                return false;
            }
            if(l_stk.top()->val!=r_stk.top()->val){
                return false;
            }
            r_left = l_stk.top()->right;//这儿经常犯错...
            r_right = r_stk.top()->left;//
            l_stk.pop();
            r_stk.pop();
        }
        return true;
    }
};
```



## 105 从前序遍历以及中序遍历构建二叉树

### 递归写法

```C++
class Solution {
public:
    unordered_map<int,int> rec_pos;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
        for(int i=0;i<n;++i)
            rec_pos[inorder[i]] = i;
        return dfs(preorder,inorder,0,n-1,0,n-1);
    }
    TreeNode* dfs(vector<int> &preorder,vector<int> &inorder,int p_l,int p_r,int i_l,int i_r){
   		if(p_l>p_r)
    		return nullptr;
        int root_val = preorder[p_l];
        int root_pos = rec_pos[root_val];
        int length = root_pos - i_l;
        auto root = new TreeNode(root_val);
        root->left = dfs(preorder,inorder,p_l+1,p_l+length,i_l,root_pos-1);
        root->right = dfs(preorder,inorder,p_l+length+1,p_r,root_pos+1,i_r);
        return root;
    }
};
```

### 迭代写法

```C++
//暂时不会
```

## 102 二叉树的层序遍历

使用队列就好写了嘛！！！先进先出

```C++
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {}; //不需要{{}}
        queue<TreeNode*> my_que;
        my_que.push(root);
        vector<vector<int>> res;
        while(my_que.size()){
            int n = my_que.size();
            for(int i=0;i<n;++i){
                auto top = my_que.front();
                vector<int> level;
                level.push_back(top->val);
                if(top->left)//记得判断是否存在
                    my_que.push(top->left);
                if(top->right)
                    my_que.push(top->right);
                my_que.pop()//需要pop,不然会TLE(time limit error)
            }
            res.push_back(level);
        }
        return res;
    }
};
```

## 寻找最近祖先

### 递归

```C++
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
    TreeNode *dfs(TreeNode *root,TreeNode *p,Treeode *q){
        if(!root)
            return nullptr;
        if(root == p ||root == q)
            return root;
        auto left = dfs(root->left,p,q);
        auto right = dfs(root->right,p,q);
        if(left && right)
            return root;
        else if(left && !right)
            return left;
        else if(!left && right)
            return right;
        else 
            return nullptr;
    }
};
```

## 二叉树的直径

```C++
class Solution {
public:
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
		dfs(root);
        return ans-1;
    }
    int dfs(TreeNode *root){
        if(!root)
            return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        ans = max(ans,L+R+1); //更新ans
        return max(left,right)+1;
    }
};
```

## 二叉树的最大深度

```c++
class Solution {
public:
    int res;
    int maxDepth(TreeNode* root) {
		return dfs(root);
    }
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        res = max(left,right)+1;
        return res;
    }
};
```

## 二叉树的最大路径和

和二叉树的最大深度一样，都是自底向上的方法，只不过这儿多一句判断，如果路径和小于0不包含子树即可

```	C++
class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if(left<0)
            left = 0;
        if(right<0)
            right = 0;
        res = max(res,left+right+root->val);
        return max(left,right)+root->val;
    }
};
```

## 687  最长同值路径

同类问题，关键在于遍历之后的处理

```C++
class Solution {
public:
    int res;
    int longestUnivaluePath(TreeNode* root) {
		dfs(root);
        return res;
    }
    int dfs(TreeNode *root){
        if(!root)
            return 0;
        auto left =dfs(root->left);
        auto right =dfs(root->right);
        if(root->left && root->left->val == root->val)
            left = left+1;
        else
            left = 0;
        if(root->right && root->right->val == root->val)
            right = right +1;
        else
            right = 0;
        res = max(res,left+right);
        return max(left,right);
    }
};
```

## 173 二叉搜索树迭代器

中序遍历的迭代写法

```	c++	
class BSTIterator {
public:
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        while(root){  //之前这儿写成了if	
            stk.push(root);
            root= root->left;
        }
    }
    
    int next() {
        auto  p =stk.top();
        stk.pop();
        auto temp = p->right;   //记得使用中间变量来保存一下
        while(temp){
            stk.push(temp);
            temp = temp->left;
        }
        return p->val;
    }
    
    bool hasNext() {
        return stk.size();
    }
};
```

