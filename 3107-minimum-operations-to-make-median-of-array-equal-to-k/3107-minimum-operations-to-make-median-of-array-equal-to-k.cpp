typedef long long ll;
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& v, int k) {
        int n = v.size();
        sort(v.begin(), v.end());
        ll ans = 0;
        for(int i = 0; i <= n / 2; i += 1) {
            if(v[i] > k) ans += (v[i] - k);
        }
        
        for(int i = n / 2; i < n; i += 1) {
            if(v[i] < k) ans += (k - v[i]);
        }
        return ans;
    }
};