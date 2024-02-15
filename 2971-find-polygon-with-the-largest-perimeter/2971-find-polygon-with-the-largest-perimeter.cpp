class Solution {
public:
    typedef long long ll;
    long long largestPerimeter(vector<int>& v) {
        int n = v.size();
        sort(v.begin(), v.end());
        vector<ll> ps(n + 1);
        for(int i = 1; i <= n; i += 1) ps[i] = ps[i - 1] + v[i - 1];
        ll ans = -1;
        for(int i = 3; i <= n; i += 1) {
            if(v[i - 1] < ps[i - 1]) {
                ans = ps[i];
            }
        }
        return ans;
    }
};