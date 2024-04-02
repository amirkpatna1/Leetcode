class Solution {
public:
    bool func(string &s,string &t){
        vector<int> charMap(256);
        for(int i=0;i<s.length();i++){
            if(charMap[s[i]]){
                if(t[i]!=charMap[s[i]]-1) return false;
            }
            else charMap[s[i]]=t[i]+1;
        }
        return true;
    }
    
    bool isIsomorphic(string s, string t) {
        return func(s,t) && func(t,s);
    }
};