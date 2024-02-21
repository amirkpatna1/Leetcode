class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // my potential ans --> left 
        if(left == 0) return 0;
        int ans = left;
        int leftBit = log2(left);
        int rightBit = log2(right);
        if(rightBit > leftBit) return 0;
        for(long i = left; i <= right; i += 1) {
            ans = (ans & i);
        }
        return ans;
    }
};