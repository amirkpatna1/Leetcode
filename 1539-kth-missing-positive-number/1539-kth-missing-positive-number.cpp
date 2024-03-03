class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int l = 0, r = v.size(), m;
        while (l < r) {
            m = (l + r) / 2;
            if (v[m] - 1 - m < k)
                l = m + 1;
            else
                r = m;
        }
        return l + k;
    }
};