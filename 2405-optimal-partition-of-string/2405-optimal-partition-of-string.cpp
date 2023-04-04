class Solution {
public:
    int partitionString(string s) {
        int n=s.length(),end=0,start=0,ans=0;
        vector<int> v(26);
        while(end<n){
            v[s[end]-'a']++;
            if(v[s[end]-'a']==2){
                ans++;
                for(int &x:v)x=0;
                v[s[end]-'a']=1;
            }
            end++;
        }
        return ans+1;
    }
};