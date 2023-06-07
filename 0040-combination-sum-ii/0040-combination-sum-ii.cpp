class Solution {
public:
    void dfs(vector<vector<int>> &ans,vector<int> &res,vector<int> &v,int &target,int i) {
        if(target == 0) {
            ans.push_back(res);
            return ;
        }
        for(int j = i; j < v.size(); j += 1) {
            if(target >= v[j]) {
                if(j == i || v[j] != v[j - 1]) {
                    target -= v[j];
                    res.push_back(v[j]);
                    dfs(ans,res,v,target,j + 1);
                    res.pop_back();
                    target += v[j];
                }
                
            } else break;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int target) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(v.begin(),v.end());
        dfs(ans,res,v,target,0);
        return ans;
    }
};