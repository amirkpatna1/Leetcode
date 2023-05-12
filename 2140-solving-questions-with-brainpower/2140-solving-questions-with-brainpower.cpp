typedef long long ll;
class Solution {
public:
    // ll dp[200002];
    // ll dfs(vector<vector<int>> &v,int i) {
    //     if(i >= v.size()) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     return dp[i] = max(dfs(v,i + 1),v[i][0] + dfs(v,i + v[i][1] + 1));
    // }
    
    // dp[i] --> represents maximum points earned from i -> n 
    
    long long mostPoints(vector<vector<int>>& v) {
        // memset(dp,-1,sizeof(dp));
        int n = v.size();
        vector<ll> dp(n + 1);
        for(int i = n - 1; i >= 0; i -= 1) {
            dp[i] = max(dp[i + 1],v[i][0] + dp[min(n,i + v[i][1] + 1)]);
        }
        // for(int i = 0; i < n; i += 1) {
        //     cout<<dp[i]<<" ";
        // }
        return dp[0];
    }
};