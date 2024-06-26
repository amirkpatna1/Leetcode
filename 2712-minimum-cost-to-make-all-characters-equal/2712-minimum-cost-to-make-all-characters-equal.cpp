typedef long long ll;
class Solution {
public:
    long long minimumCost(string s) {
        int n = s.size();
        vector<ll> ps(n);
        ll ss = 0;
        for(int i = 1; i < n; i += 1) {
            if(s[i - 1] != s[i]) {
                ps[i] += (ps[i - 1] + i);
            } else ps[i] = ps[i - 1];
        }
        ll ans = 1e14;
        for(int i = n - 2; i >= 0; i -= 1) {
            if(s[i] != s[i + 1]) ss += (n - i - 1);
            ans = min(ans,ps[i] + ss);
        }
        return min(ans,ss);
    }
};