class Solution {
public:
    vector<int> singleNumber(vector<int>& v) {
        long xr = accumulate(v.begin(), v.end(), 0, bit_xor<int>());
        
        vector<int> ans = {0, 0};
        
        xr &= -xr;
        
        
        for(int x : v) {
            if(x & xr) ans[0] ^= x;
            else ans[1] ^= x;
        }
        
        return ans;
        
    }    
};