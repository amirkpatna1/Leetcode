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
    
    void func(TreeNode *root,int &ans,int val,bool wasLeft) {
        if(!root) return ;
        ans = max(ans,val);
        if(wasLeft) {
            func(root->right,ans,val + 1,!wasLeft);
            func(root->left,ans,1,wasLeft);
            return ;
        }
        func(root->left,ans,val + 1,!wasLeft);
        func(root->right,ans,1,wasLeft);
    }
    
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        func(root->right,ans,1,false);
        func(root->left,ans,1,true);
        return ans;
    }
};