#include  <bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val_):val(val_),left(nullptr),right(nullptr){}
};

void createTree(TreeNode* &root,vector<int>& seq,int index){
    if(index>=seq.size())
        return ;
    root = new TreeNode(seq[index]);
    createTree(root->left,seq,2*index+1);
    createTree(root->right,seq,2*index+2);
}

void printT(TreeNode* p){
    if(p==nullptr){
        return ;
    }
    cout<<p->val;
    printT(p->left);
    printT(p->right);
}


int main()
{
    vector<int> a={0,1,2,3,4,5,6};
    TreeNode* root;
    createTree(root,a,0);
    printT(root);
    cout<<endl;
	return 0;
}


