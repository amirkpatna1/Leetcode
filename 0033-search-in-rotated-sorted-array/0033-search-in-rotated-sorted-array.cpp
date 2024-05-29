class Solution {
public:
    int search(vector<int>& v, int k) {
        // m > 0 && k >= 0 || m < v[0] && k <= v[0]
        // val = v[m];
        
        // k < v[0] val = INT_MIN
        // k >= v[0] val = INT_MAX
        
        int l = 0, r = v.size() - 1;
        
        while(r >= l) {
            int m = (l + r) / 2;
            int val;
            if((v[m] >= v[0] && k >= v[0]) || (v[m] < v[0] && k < v[0])) {
                val = v[m];
            } else if(k < v[0]) val = INT_MIN;
            else val = INT_MAX;
            
            if(val < k) {
                l = m + 1;
            } else r = m - 1;
        }
        return l >= v.size() ? -1 : v[l] == k ? l : -1;
        
        
    }
};