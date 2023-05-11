class Solution {
public:
    int maxUncrossedLines(vector<int>& v1, vector<int>& v2) {
        int n = v1.size(),m = v2.size();
        vector<int> dp(m + 1);
        for(int i = 1; i <= n; i += 1) {
            vector<int> temp(m + 1);
            for(int j = 1; j <= m; j += 1) {
                if(v1[i - 1] == v2[j - 1]) temp[j] = 1 + dp[j - 1];
                else temp[j] = max(dp[j],temp[j - 1]);
            }
            dp.swap(temp);
        }
        return dp[m];
    }
};