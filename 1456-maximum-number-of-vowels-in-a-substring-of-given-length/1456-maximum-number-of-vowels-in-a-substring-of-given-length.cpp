class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    int maxVowels(string s, int k) {
        int n = s.size(), start = 0, end = 0, cnt = 0, ans = 0;
        while(end < n) {
            cnt += isVowel(s[end++]);
            if(end - start > k) cnt -= isVowel(s[start++]);
            ans = max(ans,cnt);
        }
        return ans;
    }
};