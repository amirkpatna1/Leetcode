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
    int ans = 0;
    void func(TreeNode* root,string s = "") {
        if(!root) return ;
        s.push_back(root->val+'0');
        if(!(root->left || root->right)) ans += stoi(s);
        func(root->left,s);
        func(root->right,s);
        
    }
    
    int sumNumbers(TreeNode* root) {
        ans = 0;
        func(root);
        return ans;
    }
};