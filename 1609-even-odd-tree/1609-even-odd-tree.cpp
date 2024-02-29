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
    bool isEvenOddTree(TreeNode* root) {
        bool isOddLevel = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int prev = -1;
            for(int i = 0; i < n; i += 1) {
                TreeNode* node = q.front();
                q.pop();
                if(!((node->val & 1) ^ isOddLevel)) return false;
                if(i > 0 && (isOddLevel ? (prev <= node->val) : (node->val <= prev))) return false;
                prev = node -> val;
                if(node -> left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            isOddLevel = !isOddLevel;
        }
        return true;
    }
};