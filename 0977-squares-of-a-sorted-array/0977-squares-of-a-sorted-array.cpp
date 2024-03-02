class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        for(int &x : v) {
            x = x * x;
        }
        sort(v.begin(), v.end());
        return v;
    }
};