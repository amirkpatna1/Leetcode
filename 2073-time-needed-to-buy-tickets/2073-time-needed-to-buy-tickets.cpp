class Solution {
public:
    int timeRequiredToBuy(vector<int>& t, int k) {
        int res = 0;
        for (int i = 0; i < t.size(); ++i)
            res += min(t[k] - (i > k), t[i]);
        return res;
    }
};