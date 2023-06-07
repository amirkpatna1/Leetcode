class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(c) {
            if(c & 1) {
                 ans += !((a & 1) || (b & 1));
            } else {
                 ans += (a & 1) + (b & 1);
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        ans += __builtin_popcount(a);
        ans += __builtin_popcount(b);
        return ans;
    }
};