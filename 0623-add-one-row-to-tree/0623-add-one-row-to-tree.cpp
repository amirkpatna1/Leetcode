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
    void func(TreeNode* root, int val, int depth){
        if(!root) return ;
        if(depth == 2){
            TreeNode *temp1 = new TreeNode(val);
            TreeNode *temp2 = new TreeNode(val);
            temp1->left = root->left;
            temp2->right = root->right;
            root->left = temp1;
            root->right = temp2;
            return ;
        }
        func(root->left,val,depth-1);
        func(root->right,val,depth-1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left=root;
            return newRoot;
        }
        func(root,val,depth);
        return root;
    }
};