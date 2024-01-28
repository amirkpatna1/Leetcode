class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& v, int target) {
        int res = 0, m = v.size(), n = v[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 1; j < n; j++)
                v[i][j] += v[i][j - 1];

        unordered_map<int, int> counter;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                counter = {{0,1}};
                int cur = 0;
                for (int k = 0; k < m; k++) {
                    cur += v[k][j] - (i > 0 ? v[k][i - 1] : 0);
                    res += counter.find(cur - target) != counter.end() ? counter[cur - target] : 0;
                    counter[cur]++;
                }
            }
        }
        return res;
    }
};