class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> ans;
        vector<int> mins;
        vector<int> maxs;
        vector<vector<int>> matrixx(matrix[0].size(), vector<int>(matrix.size()));

        for (int i = 0; i < matrix.size(); i++) {
            int num = INT_MAX;
            for (int j = 0; j < matrix[i].size(); j++) {
                num = min(num, matrix[i][j]);
            }
            mins.push_back(num);
        }

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                matrixx[j][i] = matrix[i][j];
            }
        }

        for (int i = 0; i < matrixx.size(); i++) {
            int num = INT_MIN;
            for (int j = 0; j < matrixx[i].size(); j++) {
                num = max(num, matrixx[i][j]);
            }
            maxs.push_back(num);
        }

        for (int i = 0; i < maxs.size(); i++) {
            for (int j = 0; j < mins.size(); j++) {
                if (maxs[i] == mins[j]) {
                    ans.push_back(maxs[i]);
                }
            }
        }

        return ans;
    }
};