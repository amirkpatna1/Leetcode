class Solution {
public:
    int findKthPositive(vector<int>& v, int k) {
        int l = 0, r = v.size(), m;
        for(int i = 0; i < r; i += 1) v[i] -= (i + 1);
        while (l < r) {
            m = (l + r) / 2;
            if (v[m] < k)
                l = m + 1;
            else
                r = m;
        }
        return l + k;
    }
};