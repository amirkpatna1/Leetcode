class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans=0,prev=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==' ')ans=prev;
            while(s[i]==' ')prev=0,i++;
            if(i<s.length())prev++;
        }
        return prev==0?ans:prev;
    }
};