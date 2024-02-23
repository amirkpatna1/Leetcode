class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustCount(n);
        for(int i = 0; i < trust.size(); i += 1) {
            trustCount[trust[i][1] - 1]++;
            trustCount[trust[i][0] - 1]--;
        }
        for(int i = 0; i < n; i += 1) {
            if(trustCount[i] == n - 1) return i + 1;
        }
        return -1;
    }
};