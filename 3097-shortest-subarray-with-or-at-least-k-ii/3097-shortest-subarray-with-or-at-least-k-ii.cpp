class Solution {
public:
    int minimumSubarrayLength(vector<int>& v, int k) {
        int n = v.size();
        if(k == 0) return 1;
        vector<int> cnt(32);
        int start = 0, end = 0, res = 0, ans = 1e9;
        while(end < n) {
            res |= v[end];
            int val = v[end++];
            for(int i = 0; i < 30; i += 1) {
                if(val & (1 << i)) cnt[i] += 1;
            }
            while(res >= k) {
                ans = min(ans, end - start);
                val = v[start++];
                for(int i = 0; i < 30; i += 1) {
                    if(val & (1 << i)) {
                        if(--cnt[i] == 0) {
                            res = res & (~(1 << i));
                        }
                    }
                }
            }
        }
        return ans == 1e9 ? -1 : ans;
    }
};