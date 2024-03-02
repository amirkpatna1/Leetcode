class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        int n = v.size();
        vector<int> res(n);
        int i = 0, j = n - 1;
        for(int p = n - 1; p >= 0; p -= 1) {
            if(abs(v[i]) > abs(v[j])){
                res[p] = v[i] * v[i];
                i += 1;
            } else {
                res[p] = v[j] * v[j];
                j -= 1;
            }
        }
        return res;
    }
};