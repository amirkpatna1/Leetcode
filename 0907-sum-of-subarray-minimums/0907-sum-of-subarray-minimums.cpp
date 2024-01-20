class Solution {
public:
    int sumSubarrayMins(vector<int>& v) {
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
        while(!st.empty()){
            vr[st.top()]=n;
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && v[i]<=v[st.top()]){
                vl[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            vl[st.top()]=-1;
            st.pop();
        }
        // for(int x:vr)cout<<x<<" ";
        // cout<<endl;
        // for(int x:vl)cout<<x<<" ";
        // cout<<endl;
        long mod=1e9+7,ans=0;
        for(int i=0;i<n;i++){
            long len = (vr[i]-i)*(i-vl[i]);
            ans = (ans+ (v[i]*len) % mod)%mod;
        }
        return ans;
    }
};