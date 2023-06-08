class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int n = v.size(), m = v[0].size(), l = n - 1, r = 0;
        int cnt = 0, ans = 0;
        while(l >= 0 && r < m) {
            while(l >= 0 && v[l][r] < 0) l -= 1;
            ans += (n - l - 1 - cnt)*(m - r);
            cnt = (n - l - 1);
            while(l >= 0 && r < m && v[l][r] >= 0) r += 1;
        }
        return ans;
    }
};

// l = n - 2  ans = 4
// cnt = n - 2 , r = 2
// l = n - 3 , 
//  [4,3,2,-1]
 // [3,2,1,-1]
 // [1,1,-1,-2]
 // [-1,-1,-2,-3]