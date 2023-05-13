class Solution {
public:
    int mod = (int)1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<long> dp(100001,-1);
        function<long(int)> dfs = [&](long i) {
            if(i > high) return 0L;
            if(dp[i] != -1) return dp[i];
            long wzero = dfs(i + long(zero));
            long wone = dfs(i + long(one));
            bool flag = i >= low;
            return dp[i] = (flag + wzero + wone)%mod;
        };
        return dfs(0L);
    }
};