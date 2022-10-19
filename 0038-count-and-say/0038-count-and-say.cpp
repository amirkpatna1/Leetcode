class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=0;i<n-1;i++){
            string ss;
            int cnt=1;
            for(int j=1;j<s.length();j++){
                if(s[j]==s[j-1]){
                    cnt++;
                }
                else{
                    ss.push_back(cnt+'0');
                    ss.push_back(s[j-1]);
                    cnt=1;
                }
            }
            ss.push_back(cnt+'0');
            ss.push_back(s.back());
            s.swap(ss);
        }
        return s;
    }
};