class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // my potential ans --> left 
        if(left == 0) return 0;
        int ans = left;
        int leftBit = log2(left);
        int rightBit = log2(right);
        if(rightBit > leftBit) return 0;
        int res = 0;
        for(int i = leftBit; i >= 0; i -= 1) {
            if(!(((1 << i) & left) ^ ((1 << i) & right))) res |= ((1 << i) & left);
            else break;
        }
        return min(res, ans);
        // 011
        // 111
        
        // 011
        // 100
        // 101
        // 110
        // 111
        // 1001
        // 1100
        return ans;
    }
};