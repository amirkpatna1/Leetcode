class Solution {
public:
    
    void dfs(vector<vector<int>> &ans,vector<int> &res,vector<int> &v,int &mask) {
        if(res.size() == v.size()) {
            ans.push_back(res);
            return ;
        }
        for(int i = 0; i < v.size(); i += 1) {
            if((mask & (1 << i))) continue;
            mask |= (1 << i);
            res.push_back(v[i]);
            dfs(ans,res,v,mask);
            res.pop_back();
            mask = mask & ~(1 << i);
        }
    }
    
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> res;
        int mask = 0;
        dfs(ans,res,v,mask);
        return ans;
    }
};