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
    
    
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool found = false;
        while(!q.empty()) {
            int sz = q.size();
            bool flag = false;
            TreeNode *prev ;
            for(int i = 0; i < sz; i += 1) {
                TreeNode *node = q.front();
                q.pop();
                if(node && (found || (!prev && i != 0) )) return false;
                if(!node) {
                    flag = true;
                }
                if(node) {
                    q.push(node->left);
                    q.push(node->right);
                }
                prev = node;
                
            }
            found = flag;
            
        }
        return true;
    }
};