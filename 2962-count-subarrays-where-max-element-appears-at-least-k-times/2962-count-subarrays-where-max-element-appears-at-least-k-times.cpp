class Solution {
public:
     long long countSubarrays(vector<int>& v, int k) {
        int a = *max_element(v.begin(), v.end()), n = v.size(), cur = 0, i = 0;
        long long res = 0;
        for (int j = 0; j < n; ++j) {
            cur += v[j] == a;
            while (cur >= k)
                cur -= v[i++] == a;
            res += i;
        }
        return res;
    }
};