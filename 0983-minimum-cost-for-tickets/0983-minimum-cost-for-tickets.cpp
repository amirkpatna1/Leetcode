class Solution {
public:
    int func(vector<int> &days,vector<int> &costs,int i,vector<int> &dp) {
        if(i >= days.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = costs[0] + func(days,costs,i + 1,dp);
        int indexAfterSevenDayPass = upper_bound(days.begin(),days.end(),days[i] + 6) - days.begin();
        int indexAfterThirtyDayPass = upper_bound(days.begin(),days.end(),days[i] + 29) - days.begin();
        ans = min({ans,costs[1] + func(days,costs,indexAfterSevenDayPass, dp),costs[2] + func(days,costs,indexAfterThirtyDayPass, dp)});
        return dp[i] = ans;
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // sort(days.begin(),days.end());
        int n = days.size();
        vector<int> dp(n, -1);
        return func(days,costs,0,dp);
    }
};