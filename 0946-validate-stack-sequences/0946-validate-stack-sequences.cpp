class Solution {
public:
    bool validateStackSequences(vector<int>& p, vector<int>& po) {
        stack<int> st;
        int j=0;
        for(int i=0;i<p.size();i++){
            // if(p[i]==po[j]){
            //     j++;continue;
            // }
            st.push(p[i]);
            while(!st.empty() && st.top()==po[j]){
                j++;
                st.pop();
            }
        }
        return st.empty();
    }
};