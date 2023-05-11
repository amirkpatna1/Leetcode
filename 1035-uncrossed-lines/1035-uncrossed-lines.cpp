class Solution {
public:
    int dp[501][501];
    int maxUncrossedLines(vector<int>& v1, vector<int>& v2) {
        int n = v1.size(),m = v2.size();
        for(int i = 1; i <= n; i += 1) {
            for(int j = 1; j <= m; j += 1) {
                if(v1[i - 1] == v2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};