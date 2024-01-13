class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> v(26);
        for(char c : s) v[c - 'a'] += 1;
        for(char c : t) v[c - 'a'] -= 1;
        int ans = 0;
        for(int x : v) ans += abs(x);
        return ans / 2;
    }
};