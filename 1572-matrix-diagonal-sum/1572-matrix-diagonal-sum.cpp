class Solution {
public:
    int diagonalSum(vector<vector<int>>& v) {
        int n = v.size();
        int ans = (n&1) ? -v[n/2][n/2] : 0;
        for(int i = 0; i < n; i += 1) {
            ans += (v[i][i] + v[i][n - i - 1]);
        }
        return ans;
    }
};