class Solution {
public:
    string customSortString(string o, string s) {
        vector<short> v(26, 27);
        short cnt = 0;
        for(char c : o) {
            v[c - 'a'] = cnt++;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            return v[a - 'a'] < v[b - 'a'];
        });
        return s;
    }
};