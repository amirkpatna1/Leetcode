class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int i=-1,j=-1;
        vector<int> v(26);
        for(int k=0;k<s.length();k++){
            if(s[k]!=goal[k]){
                if(i==-1)i=k;
                else if(j==-1){
                    j=k;break;
                }
            }
            v[s[k]-'a']++;
        }
        if(j==-1 && i==-1){
            for(int x:v){
                if(x>1)return true;
            }
            return false;
        }
        if(j == -1) return false;
        swap(s[i],s[j]);
        return s==goal;
    }
};