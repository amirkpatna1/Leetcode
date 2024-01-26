class Solution {
public:
    typedef long long ll;
    long long minimumCost(vector<int>& v, int k, int dist) {
        k -= 1;
        multiset<ll> right;
        multiset<ll, greater<ll>> left;
        ll start = 1LL, end = 1LL, cnt = 0LL, ans = 1e18, n = v.size();
        while(end < n) {
            cnt += (ll)v[end];
            left.insert(v[end]);
            end += 1;
            if(!(left.size() || right.size()) && *left.begin() > *right.begin()) {
                ll a = *left.begin();
                ll b = *right.begin();
                cnt += (b - a);
                left.erase(left.begin());
                right.erase(right.begin());
                right.insert(a);
                left.insert(b);
            }
            if(left.size() > k) {
                ll a = *left.begin();
                cnt -= a;
                right.insert(a);
                left.erase(left.begin());
            }
            if(end - start > dist + 1) {
                if(right.count(v[start])) {
                    right.erase(right.find(v[start]));
                    start += 1;
                } else {
                    cnt -= v[start];
                    left.erase(left.find(v[start]));
                    start += 1;
                    if(left.size() < k && !right.empty()) {
                        int a = *right.begin();
                        cnt += a;
                        left.insert(a);
                        right.erase(right.begin());
                    }
                }
            }
            if(end - start == dist + 1) {
                ans = min(ans, cnt);
            }
            
        }
        return ans + v[0];
    }
};