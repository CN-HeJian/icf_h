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

迭代写法

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

