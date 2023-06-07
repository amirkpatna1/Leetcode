class Solution {
public:
    
    void dfs(vector<vector<int>> &ans,vector<int> &res,vector<int> &v,int i) {
        ans.push_back(res);
        for(int j = i; j < v.size(); j += 1) {
            if(j == i || v[j] != v[j - 1]) {
                res.push_back(v[j]);
                dfs(ans,res,v,j + 1);
                res.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& v) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(v.begin(),v.end());
        dfs(ans,res,v,0);
        return ans;
    }
};