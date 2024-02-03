class Solution {
public:
    int dp[501];
    int func(vector<int> &v,int k,int i){
        if(i==v.size()) return 0;
        int mx=0,res=0;
        if(dp[i]!=-1)return dp[i];
        for(int j=i;j<min((int)v.size(),i+k);j++){
            mx=max(mx,v[j]);
            res=max(res,mx*(j-i+1)+func(v,k,j+1));
        }
        return dp[i]=res;
    }
    
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        memset(dp,-1,sizeof(dp));
        return func(v,k,0);
    }
};