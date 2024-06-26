class Solution {
public:
    int search(vector<int>& v, int target) {
        int l = 0,r = v.size() - 1;
        while(r >= l) {
            int m = (l + r)/2;
            if(v[m] == target) return m;
            if(v[m] > target) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};