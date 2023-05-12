typedef long long ll;
class Solution {
public:
    ll dp[100001];
    ll dfs(vector<vector<int>> &v,int i) {
        if(i >= v.size()) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = max(dfs(v,i + 1),v[i][0] + dfs(v,i + v[i][1] + 1));
    }
    long long mostPoints(vector<vector<int>>& v) {
        memset(dp,-1,sizeof(dp));
        return dfs(v,0);
    }
};