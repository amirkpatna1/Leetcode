class Solution {
public:
    int dp[301][11];
    int func(vector<int> &v,int i,int d){
        if(d==0 && i==v.size())return 0;
        if(d<0 || i==v.size())return 1e9;
        int mx=-1e9;
        int ans=1e9;
        if(dp[i][d]!=-1)return dp[i][d];
        for(int j=i;j<v.size();j++){
            mx=max(mx,v[j]);
            ans=min(ans,mx+func(v,j+1,d-1));
        }
        return dp[i][d]=ans;
    }
    
    // dp[i][d] --> minimum difficulty to complete i+1 jobs in d days
    // dp[0][0] = 0;
    // space -- O(n*d)
    // time -- O(n*n*d);
    // --> 0 jobs in 1 to d days it will take 0 difficulty
    // 1 job in 1 to d days it will take x difficulty
    // 2 job in 1 day --> x1+x2
    // 2 job in >=2 days -- > max(x1,x2);
    // dp[i][d] = min(max value uptil j and )
    int minDifficulty(vector<int>& v, int d) {
        memset(dp,-1,sizeof(dp));
        int ans = func(v,0,d);
        if(ans>=1e9)return -1;
        return ans;
        // dp[i][j]=mx+dp[j-1][d+1];
        
        // int n=v.size();
        // vector<vector<int>> dp(n+1,vector<int>(d+1,1e9));
        // dp[n][0]=0;
        // for(int i=n-1;i>=0;i--){
        //     for(int j=d;j>=1;j--){
        //         int mx=-1e9,mn=1e9;
        //         for(int k=i;k<n;k++){
        //             mx = max(mx,v[k]);
        //             mn = min(mn,mx+dp[k+1][j-1]);
        //         }
        //         dp[i][j]=mn;
        //     }
        // }
        // for(auto vv:dp){
        //     for(int x:vv)cout<<x<<" ";
        //     cout<<endl;
        // }
        // return dp[n][0];
    }
};