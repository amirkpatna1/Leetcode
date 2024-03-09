class Solution {
public:
    int getCommon(vector<int>& u, vector<int>& v) {
        sort(u.begin(), u.end());
        sort(v.begin(), v.end());
        for(int x : u) {
            auto it = lower_bound(v.begin(), v.end(), x);
            if(it != v.end() && *it == x) return x;
        }
        return -1;
    }
};