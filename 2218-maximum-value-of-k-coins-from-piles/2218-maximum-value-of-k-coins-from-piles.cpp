class Solution {
public:
    int dp[1001][2001];
    int func(vector<vector<int>> &piles,int k,int i) {
        if(k == 0 || i >= piles.size()) return 0;
        if(dp[i][k] != -1) return dp[i][k];
        int mx = 0, s = 0;
        for(int j = 0; j <= piles[i].size(); j += 1) {
            if(j > k) break;
            mx = max(mx,s + func(piles,k - j, i + 1));
            s += j < piles[i].size() ? piles[i][j] : 0;
        }
        return dp[i][k] = mx;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp,-1,sizeof(dp));
        return func(piles,k,0);
    }
};