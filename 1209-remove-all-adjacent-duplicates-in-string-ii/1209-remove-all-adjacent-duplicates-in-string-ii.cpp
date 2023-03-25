class Solution {
public:
    string removeDuplicates(string s, int k) {
        int cnt=0;
        char prev=s[0];
        stack<pair<char,int>> st;
        for(int i=0;i<=s.length();i++){
            if(i+1<s.length() && s[i]==prev){
                cnt++;
            }
            else{
                if(!st.empty() && st.top().first==prev){
                    cnt+=st.top().second;
                    st.pop();
                }
                if(cnt%k)st.push({prev,cnt%k});
                cnt=1;
                prev=s[i];
            }
        }
        string ans;
        while(!st.empty()){
            ans+=string(st.top().second,st.top().first);
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};