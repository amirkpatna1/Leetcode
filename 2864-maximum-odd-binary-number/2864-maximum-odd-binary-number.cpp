class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = count(s.begin(), s.end(), '1');
        string a = string(ones - 1, '1');
        string b = string(s.size() - ones, '0');
        return a + b + "1";
    }
};