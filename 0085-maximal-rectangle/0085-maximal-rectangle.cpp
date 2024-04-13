class Solution {
public:
    
    int hist(vector<int> &v){
        int n=v.size();
        vector<int> vl(n),vr(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && v[i]<v[st.top()]){
                vr[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())vr[st.top()]=n,st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && v[i]<v[st.top()]){
                vl[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty())vl[st.top()]=-1,st.pop();
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,v[i]*(vr[i]-vl[i]-1));
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& v) {
        int n=v.size(),m=v[0].size();
        vector<int> temp(m);
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)temp[j]+=v[i][j]=='0'?-temp[j]:1;
            ans=max(ans,hist(temp));
        }
        return ans;
    }
};