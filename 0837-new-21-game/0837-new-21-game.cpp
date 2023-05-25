class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        int a=0,tot=0;
        if(n>=k+maxPts || k==0)return 1.00000;
        vector<double> dp(n+1);
        dp[0]=1.0;
        double ans=0,s=1.0;
        for(int i=1;i<=n;i++){
            dp[i]=s/maxPts;
            if(i<k)s+=dp[i];
            else ans+=dp[i];
            if(i-maxPts>=0)s-=dp[i-maxPts];
        }
        return ans;
    }
};