class Solution {
public:
    int longestConsecutive(vector<int>& v) {
        unordered_set<int> st(v.begin(),v.end());
        int ans = 0, cnt = 1;
        for(int x : v) {
            if(!st.count(x - 1)) {
                int val = x + 1;
                while(st.count(val++)) cnt += 1;
            }
            ans = max(ans,cnt);
            cnt = 1;
        }
        return ans;
    }
};