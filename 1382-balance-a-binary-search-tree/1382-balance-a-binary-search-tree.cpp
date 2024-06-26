/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void inorder(TreeNode* root,vector<int> &v){
        if(!root)return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    TreeNode* func(vector<int> &v,int l,int r){
        if(l>r)return NULL;
        int m=(l+r)/2;
        TreeNode* node=new TreeNode(v[m]);
        node->left=func(v,l,m-1);
        node->right=func(v,m+1,r);
        return node;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        return func(v,0,v.size()-1);
    }
};