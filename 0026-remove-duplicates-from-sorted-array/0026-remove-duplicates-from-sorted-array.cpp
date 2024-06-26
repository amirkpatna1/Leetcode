class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int cnt = 0, n = v.size();
        for(int i = 1; i < n; i += 1) {
            if(v[i] == v[i - 1]) {
                cnt += 1;
            } else {
                v[i - cnt] = v[i];
            }
        }
        return n - cnt;
    }
};