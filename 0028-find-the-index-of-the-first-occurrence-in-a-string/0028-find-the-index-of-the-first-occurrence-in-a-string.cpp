class Solution {
public:
    int strStr(string s, string v) {
        int x = s.find(v);
        return x != string::npos ? x : -1;
    }
};