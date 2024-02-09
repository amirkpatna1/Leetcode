class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<int> dp(n), prev(n, -1);
        int idx = 0;
        for(int i = 1; i < n; i += 1) {
            for(int j = 0; j < i; j += 1) {
                if(v[i] % v[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            idx = dp[i] > dp[idx] ? i : idx;
        }
        vector<int> ans;
        while(idx >= 0) {
            ans.push_back(v[idx]);
            idx = prev[idx];
        }
        return ans;
    }
};