class Solution {
public:
    int dp[501][501];
    int func(string &s,int i,int j){
        if(i>=j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])return dp[i][j]=func(s,i+1,j-1);
        return dp[i][j]=1+min(func(s,i+1,j),func(s,i,j-1));
    }
    
    int minInsertions(string s) {
        memset(dp,-1,sizeof(dp));
        return func(s,0,s.length()-1);
    }
};