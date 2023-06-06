class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int n = v.size(),m = v[0].size();
        int l = 0,r = n * m - 1;
        while(r >= l) {
            int mid = (l + r)/2;
            int row = mid / m;
            int col = mid % m;
            if(target == v[row][col]) return true;
            if(target > v[row][col]) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};