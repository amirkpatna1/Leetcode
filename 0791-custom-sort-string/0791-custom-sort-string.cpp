class Solution {
public:
    string customSortString(string o, string s) {
        vector<int> v(26, 27);
        int cnt = 0;
        for(char c : o) {
            v[c - 'a'] = cnt++;
        }
        sort(s.begin(), s.end(), [&](char a, char b) {
            return v[a - 'a'] < v[b - 'a'];
        });
        return s;
    }
};