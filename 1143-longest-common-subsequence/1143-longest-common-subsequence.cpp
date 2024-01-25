class Solution {
public:
    int longestCommonSubsequence(string &s1, string &s2) {
        int n=s1.length(),m=s2.length();
        vector<int> dp(m+1);
        for(int i=1;i<=n;i++){
            vector<int> tmp(m+1);
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])tmp[j]=1+dp[j-1];
                else tmp[j]=max(dp[j],tmp[j-1]);
            }
            dp.swap(tmp);
        }
        return dp[m];
    }
};