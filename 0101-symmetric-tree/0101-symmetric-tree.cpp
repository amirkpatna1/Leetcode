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
    bool func(TreeNode *root,TreeNode *node){
        if(!(root || node)) return true;
        if(!(root && node)) return false;
        return root->val==node->val && func(root->left,node->right) && func(root->right,node->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return func(root->left,root->right);
    }
};