class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n));
        int ans=n;
        for(int i=0;i<n;i++)dp[i][i]=true;
        for(int i=0;i<n-1;i++)ans+=dp[i][i+1]=s[i]==s[i+1];
        for(int i=2;i<=n;i++){
            for(int j=0;j+i<=n;j++){
                if(s[j]==s[j+i-1] && dp[j+1][j+i-2]){
                    ans++;
                    dp[j][j+i-1]=true;
                }
            }
        }
        return ans;
    }
};