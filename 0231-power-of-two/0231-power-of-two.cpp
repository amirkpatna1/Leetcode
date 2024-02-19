class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == -1) return false;
        if(n < 0) {
            return !(n & (n + 1));
        } else if(n > 0) {
            return !(n & (n - 1));
        }
        
        return 0;
    }
};