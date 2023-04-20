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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int ans=1;
        while(!q.empty()){
            int sz=q.size();
            int mn=q.front().second,mx=q.back().second;
            ans=max(ans,mx-mn+1);
            while(sz--){
                auto p=q.front();
                q.pop();
                TreeNode *node=p.first;
                int idx=p.second-mn;
                if(node->left){
                    q.push({node->left,(long long)2*idx+1});
                }
                if(node->right)q.push({node->right,(long long)2*idx+2});
            }
        }
        return ans;
    }
};