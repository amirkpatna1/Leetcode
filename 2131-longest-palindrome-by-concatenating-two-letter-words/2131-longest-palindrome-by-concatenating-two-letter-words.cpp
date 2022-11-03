class Solution {
public:
    int longestPalindrome(vector<string>& v) {
        map<string,int> mp;
        int n=v.size();
        for(int i=0;i<n;i++){
            mp[v[i]]++;
        }
        int ans=0,cnt=0;
        for(auto p:mp){
            string pp=p.first;
            int ss=p.second;
            if(pp[0]==pp[1]){
                if(ss>1)ans+=4*(ss/2);
                cnt =cnt || (ss&1);
            }
            else{
                string s=pp;
                reverse(s.begin(),s.end());
                ans+=2*min(ss,mp[s]);
            }
        }
        return ans+2*cnt;
    }
};