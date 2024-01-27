class Solution {
public:
    int mod=1e9+7;
    int func(int n,int k,vector<vector<int>> &dp){
        if(n==0)return 0;
        if(k<=0)return k==0;
        if(dp[n][k])return dp[n][k];
        int inv=0;
        for(int i=0;i<n;i++){
            inv=(inv + func(n-1,k-i,dp))%mod;
        }
        return dp[n][k]=inv;
    }
    
    int kInversePairs(int n, int k) {
        int dp[1001][1001] = { 1 };
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K)
                for (int i = 0; i <= min(K, N - 1); ++i) 
                    dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % 1000000007;
        return dp[n][k];
    }
};