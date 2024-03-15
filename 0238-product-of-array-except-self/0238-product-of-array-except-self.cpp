class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {
        int n = v.size();
        vector<int> ans(n, 1);
        int val = v[0];
        for(int i = 1; i < n; i += 1) {
            ans[i] = val;
            val *= v[i];
        }
        val = v.back();
        for(int i = n - 2; i >= 0; i -= 1) {
            ans[i] *= val;
            val *= v[i];
        }
        return ans;
    }
};