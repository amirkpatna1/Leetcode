class Solution {
public:
    vector<int> dir={1,-1,0};
    int func(vector<vector<int>> &v,int i,int c1,int c2,vector<vector<vector<int>>> &dp){
        if(c1<0 || c2<0 || c1>=v[0].size() || c2>=v[0].size()) return -1e9;
        if(i==v.size())return 0;
        int ans=0;
        if(dp[i][c1][c2]!=-1)return dp[i][c1][c2];
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                ans=max(ans,func(v,i+1,c1+dir[j],c2+dir[k],dp));
            }
        }
        ans+=c1==c2?v[i][c1]:v[i][c1]+v[i][c2];
        return dp[i][c1][c2]=ans;
        
    }
    
    int cherryPickup(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(m+1,-1)));
         return func(v,0,0,m-1,dp);
    }
};