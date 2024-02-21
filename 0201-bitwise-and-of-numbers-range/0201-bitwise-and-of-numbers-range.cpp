class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0) return 0;
        int leftBit = log2(left);
        int rightBit = log2(right);
        if(rightBit > leftBit) return 0;
        int res = left;
        for(int i = leftBit; i >= 0; i -= 1) {
            if(((1 << i) & left) ^ ((1 << i) & right)) return res & (~((1LL << (i + 1)) - 1));
        }
        return res;
    }
};