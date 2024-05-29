class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {
        int l = 0, r = v.size() - 1;
        int n = v.size();
        while(r >= l) {
            int m = (l + r) / 2;
            if(v[m] != (m + 1 < n ? v[m + 1] : -1) && v[m] != (m - 1 >= 0 ? v[m - 1] : -1)) return v[m];
            if((m % 2 == 0 && m + 1 < n && v[m] == v[m + 1]) || (m % 2 != 0 && m - 1 >= 0 && v[m] == v[m - 1])) {
                l = m + 1;
            }
        
            else {
                r = m - 1;
            }
        }
        return -1;
    }
};