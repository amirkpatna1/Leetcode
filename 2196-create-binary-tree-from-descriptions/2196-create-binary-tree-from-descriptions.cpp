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
    
    TreeNode* func(int val,unordered_map<int,vector<int>> &mp){
        TreeNode* root=new TreeNode(val);
        if(mp[val].size()==2){
            if(mp[val][0]<0)root->left=func(-mp[val][0],mp);
            else root->right=func(mp[val][0],mp);
            if(mp[val][1]<0)root->left=func(-mp[val][1],mp);
            else root->right=func(mp[val][1],mp);
        }
        else if(mp[val].size()==1){
            if(mp[val][0]<0)root->left=func(-mp[val][0],mp),root->right=NULL;
            else root->right=func(mp[val][0],mp),root->left=NULL;
        }
        return root;
    }
    
    TreeNode* createBinaryTree(vector<vector<int>>& v) {
        unordered_map<int,int> mp;
        unordered_map<int,vector<int>> mp1;
        for(auto &vv:v){
            mp[vv[1]]++;
            if(vv[2])mp1[vv[0]].push_back(-vv[1]);
            else mp1[vv[0]].push_back(vv[1]);
        }
        int root=-1;
        for(auto &vv:v){
            if(!mp.count(vv[0])){
                root=vv[0];
                break;
            }
        }
        return func(root,mp1);
    }
};