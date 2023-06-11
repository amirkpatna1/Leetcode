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
    void dfs(vector<int> &ans,TreeNode *root,int height) {
        if(!root) return ;
        dfs(ans,root->left,height + 1);
        dfs(ans,root->right, height + 1);
        ans[height] = root->val;
    }
    
    void getMaxHeight(TreeNode *root,int height,int &maxHeight) {
        if(!root) return ;
        getMaxHeight(root->left,height + 1, maxHeight);
        getMaxHeight(root->right,height + 1, maxHeight);
        maxHeight = max(maxHeight, height);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        int maxHeight = 0;
        getMaxHeight(root,0,maxHeight);
        vector<int> ans(maxHeight + 1);
        dfs(ans,root,0);
        return ans;
    }
};