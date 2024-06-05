class Solution {
public:
    vector<string> commonChars(vector<string>& vs) {
        vector<int> v(26, 1e9);
        int n = vs.size();
        for(string &s : vs) {
            vector<int> u(26);
            for(char c : s) {
                u[c - 'a'] += 1;
            }
            for(int i = 0; i < 26; i += 1) v[i] = min(v[i], u[i]);
        }
        
        vector<string> ans;
        
        for(int i = 0; i < 26; i += 1) {
            while(v[i]-- > 0) {
                ans.push_back(string(1, i + 'a'));
            }
        }
        return ans;
    }
};