class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j] represents min path sum from 0,0 to i,j
        // base cases path sum from 0,0 to 0,0 is --> 0
        // case 2 
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i += 1) dp[i][0] = dp[i-1][0] + grid[i][0];
        for(int j = 1; j < m; j += 1) dp[0][j] = dp[0][j-1] + grid[0][j];
        for(int i = 1; i < n; i += 1) {
            for(int j = 1; j < m; j += 1) {
                dp[i][j] = grid[i][j]+min(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        return dp[n-1][m-1];
    }
};