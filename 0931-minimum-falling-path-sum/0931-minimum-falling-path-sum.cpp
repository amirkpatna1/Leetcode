class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& v) {
        int n = v.size() , m = v[0].size();
        for(int i = 1; i < n; i += 1) {
            for(int j = 0; j < m; j += 1) {
                v[i][j] += min({v[i - 1][j],v[i-1][max(0,j-1)],v[i-1][min(m-1,j+1)]});
            }
        }
        return *min_element(v.back().begin(),v.back().end());
    }
};