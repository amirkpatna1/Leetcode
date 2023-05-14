typedef long long ll;
class Solution {
public:
    long long maximumOr(vector<int>& v, int k) {
        int n = v.size();
        vector<ll> suffixOr(n + 1);
        for(int i = n - 1; i >= 0; i -= 1) {
            suffixOr[i] = v[i] | suffixOr[i + 1];
        }
        ll prefixOr = 0;
        ll valToOr = 1 << k;
        ll ans = 0;
        for(int i = 0; i < n; i += 1) {
            ll val = v[i] * valToOr;
            ans = max(ans,prefixOr | val | suffixOr[i + 1]);
            prefixOr |= v[i];
        }
        return ans;
    }
};