class Solution {
public:

    // 1 --> profit < minProfit. --->will give me profit > minProfit 
    // 2 --> group > n
    // profit < minProfit && group > n
    //profit <= minProfit && group < n --> can be calculated right ? yes. 
    //group <= n
    //profit > minProfit && group < n || profit < minProfit && group > n

    // group > n. I have
    int profitableSchemes(int G, int P, vector<int> group, vector<int> profit) {
        vector<vector<int>> dp(P + 1, vector<int>(G + 1, 0));
        dp[0][0] = 1;
        int res = 0, mod = 1e9 + 7;
        for (int k = 0; k < group.size(); k++) {
            int g = group[k], p = profit[k];
            for (int i = P; i >= 0; i--)
                for (int j = G - g; j >= 0; j--)
                    dp[min(i + p, P)][j + g] = (dp[min(i + p, P)][j + g] + dp[i][j]) % mod;
        }
        for (int x: dp[P]) res = (res + x) % mod;
        return res;
    }
};