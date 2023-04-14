class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.length(),ans=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1));
        for(int i=0;i<n;i++)dp[i][i]=1,ans=1;
        for(int i=0;i<n-1;i++)dp[i][i+1]=(s[i]==s[i+1])+1,ans=max(ans,dp[i][i+1]);
        for(int i=2;i<=n;i++){
            for(int j=0;j+i<=n;j++){
                if(s[j]==s[j+i-1])dp[j][j+i-1]=2+dp[j+1][j+i-2];
                else dp[j][j+i-1]=max(dp[j+1][j+i-1],dp[j][j+i-2]);
                ans=max(ans,dp[j][j+i-1]);
            }
        }
        return ans;
    }
};