class Solution {
public:
    int minimumLength(string s) {
        int n = s.size();
        int l = 0, r = n - 1;
        while(r > l && s[r] == s[l]) {
            char c = s[l];
            while(r >= l && s[l] == c) l += 1;
            while(r >= l && s[r] == c) r -= 1;
        }
        return r - l + 1;
    }
};