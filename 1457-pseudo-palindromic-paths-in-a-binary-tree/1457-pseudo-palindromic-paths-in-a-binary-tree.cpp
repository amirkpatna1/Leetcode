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
    void func(TreeNode* root,int mask,int total){
        if(!root) return ;
        mask ^= (1<<root->val);
        total++;
        if(!(root->left || root->right)){
            int oddCount = 0 , tempMask = mask;
            while(tempMask){
                if(tempMask&1)oddCount++;
                tempMask >>= 1;
            }
            if((oddCount==1 && (total&1)) || oddCount==0)ans++;
        }
        func(root->left,mask,total);
        func(root->right,mask,total);
        
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        ans = 0;
        func(root,0,0);
        return ans;
    }
};