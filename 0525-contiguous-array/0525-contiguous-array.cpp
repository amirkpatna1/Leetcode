class Solution {
public:
    int findMaxLength(vector<int>& v) {
        int n = v.size(), start = 0, end = 0, cnt = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        int s = 0;
        for(int i = 0; i < n; i += 1) {
            s += (v[i] == 0 ? -1 : 1);
            if(mp.count(s)) {
                ans = max(ans, i - mp[s] + 1);
            } else mp[s] = i;
        }
        return max(0, ans - 1);
        // 0 1 1
        // 0 1 0 1 1 1 0 0 0
        // 0 1 1 2 3 4 4 4 4
        // -1 0 -1 0 1 2 1 0 -1 -2
    }
};