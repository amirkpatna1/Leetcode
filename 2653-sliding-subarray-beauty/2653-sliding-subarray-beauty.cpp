class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& v, int k, int x) {
        vector<int> ans;
        vector<int> mp(101);
        int start = 0,end = 0,n = v.size();
        while(end < n) {
            mp[v[end] + 50]++;
            end++;
            if(end - start > k) {
                mp[v[start++] + 50]--;
            }
            if(end - start == k) {
                int cnt = 0, val;
                for(int i = 0; i <= 100; i += 1) {
                    cnt += mp[i];
                    if(cnt >= x) {
                        val = i - 50;
                        break;
                    }
                }
                ans.push_back(val > 0 ? 0 : val);
            }
        }
        return ans;
    }
};