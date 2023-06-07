class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans = 0;
        while(c) {
            if(c & 1) {
                if(!((a & 1) || (b & 1))) ans += 1;
            } else {
                 if(a & 1) ans += 1;
                if(b & 1) ans += 1;
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