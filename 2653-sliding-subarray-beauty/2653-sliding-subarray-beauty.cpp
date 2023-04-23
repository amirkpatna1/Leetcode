class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& v, int k, int x) {
        vector<int> ans;
        vector<vector<int>> mp(101);
        int start = 0,end = 0,n = v.size();
        while(end < n) {
            mp[v[end] + 50].push_back(v[end++]);
            if(end - start > k) {
                mp[v[start] + 50].pop_back();
                start++;
            }
            if(end - start == k) {
                int cnt = 0, val;
                for(int i = 0; i <= 100; i += 1) {
                    cnt += mp[i].size();
                    if(cnt >= x) {
                        val = mp[i][0];
                        break;
                    }
                }
                ans.push_back(val > 0 ? 0 : val);
            }
        }
        return ans;
    }
};