class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> v(n);
        int o = 0;
        for(int i = 0; i < n; i += 1) {
            char c = s[i];
            if(c == '(') o += 1;
            else if(c == ')') {
                if(o == 0) v[i] = true;
                else o -= 1;
            }
        }
        string ans;
        for(int i = n - 1; i >= 0; i -= 1) {
            if(o > 0 && s[i] == '(') {
                o -= 1;
                continue;
            }
            if(v[i]) continue;
            ans.push_back(s[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};