class Solution {
public:
    
    // (u(love)i)abc
    // (u(love
    // evol
    // (uevoli
    // iloveu
     // iloveuabc
     
    
    string reverseParentheses(string s) {
        vector<char> v;
        int i=0;
        while(i<s.length()){
            while(i<s.length() && s[i]!=')'){
                v.push_back(s[i++]);
            }
            if(i==s.length())break;
            i++;
            string ss;
            while(v.back()!='('){
                ss.push_back(v.back());
                v.pop_back();
            }
            v.pop_back();
            for(char &c:ss)v.push_back(c);
        }
        string ans(v.begin(),v.end());
        return ans;
    }
};