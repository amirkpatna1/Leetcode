typedef long long ll;

class Solution {
public:
    ll mod = (ll)1e9+7;
    int dp[100001];
    int func(string &s , int i,int k) {
        if(i >= s.size()) return 1;
        string ss;
        ll mx = 0;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < s.size(); j += 1) {
            ss.push_back(s[j]);
            // cout<<ss<<" ";
            ll val = stoll(ss);
            if(val <= k) mx = (mx + func(s,j + 1,k))%mod;
            else break;
        }
        return dp[i] = mx;
    }
    
    int numberOfArrays(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return func(s,0,k);
    }
};