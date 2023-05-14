typedef long long ll;
class Solution {
public:
    long long maximumOr(vector<int>& v, int k) {
        int n = v.size();
        vector<ll> ss(n + 1);
        for(int i = n - 1; i >= 0; i -= 1) {
            ss[i] = v[i] | ss[i + 1];
        }
        ll ps = 0;
        ll valToOr = 1 << k;
        ll ans = 0;
        for(int i = 0; i < n; i += 1) {
            ll val = v[i] * valToOr;
            ans = max(ans,ps | val | ss[i + 1]);
            ps |= v[i];
        }
        return ans;
    }
};