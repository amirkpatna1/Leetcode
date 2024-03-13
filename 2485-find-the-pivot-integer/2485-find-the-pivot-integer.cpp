class Solution {
public:
    int pivotInteger(int n) {
        int s = n*(n+1)/2;
        for(int i = 1 ; i <= n ; i++) {
            int ss = i*(i+1)/2;
            if(ss == s - ss + i) return i;
        }
        return -1;
    }
};