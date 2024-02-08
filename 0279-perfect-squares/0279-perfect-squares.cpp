class Solution {
public:
    // int dp[10001];
    // int func(int n) {
    //     if(n==0) return 0;
    //     int mn=1e9;
    //     if(dp[n]!=-1)return dp[n];
    //     for(int i=1;i*i<=n;i++){
    //         int val= i*i;
    //         mn=min(mn,1+func(n-val));
    //     }
    //     return dp[n]=mn;
    // }
    int numSquares(int n) {
        // memset(dp,-1,sizeof(dp));
        // return func(n);
        vector<int> dp(n+1,1e9);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};