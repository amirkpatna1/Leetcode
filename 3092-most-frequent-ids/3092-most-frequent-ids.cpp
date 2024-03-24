

typedef long long ll;
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& v, vector<int>& freq) {
        int n = v.size();
        unordered_map<int, ll> mp;
        vector<ll> ans(n);
        multiset<ll> ms;
        for(int i = 0; i < n; i += 1) {
            auto it = ms.find(mp[v[i]]);
            mp[v[i]] += freq[i];
            if(it != ms.end()) {
                ms.erase(it);
            }
            ms.insert(mp[v[i]]);
            
            ll val = *(--ms.end());
            ans[i] = val;
            
        }
        return ans;
    }
};