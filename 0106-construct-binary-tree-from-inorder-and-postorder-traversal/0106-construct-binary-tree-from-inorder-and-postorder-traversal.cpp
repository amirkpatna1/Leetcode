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
    int p=0;
    TreeNode* func(vector<int> &inorder,vector<int> &post,int i,int j){
        if(i>j)return NULL;
        TreeNode *root=new TreeNode(post[p]);
        int idx=find(inorder.begin(),inorder.end(),post[p++])-inorder.begin();
        root->right=func(inorder,post,idx+1,j);
        root->left=func(inorder,post,i,idx-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end());
        return func(inorder,postorder,0,inorder.size()-1);
    }
};