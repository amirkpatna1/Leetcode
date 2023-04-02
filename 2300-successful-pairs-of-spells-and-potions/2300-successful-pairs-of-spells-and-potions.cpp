typedef long long ll;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& a, vector<int>& b, long long s) {
        // sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int n = a.size();
        vector<int> ans;
        for(int i = 0; i < n; i += 1) {
            ll val = (s + a[i] - 1)/a[i];
            ll idx = lower_bound(b.begin(),b.end(),val) - b.begin();
            ans.push_back((ll)b.size() - idx);
        }
        return ans;
    }
};