class Solution {
public:
    
    void func(vector<int> &ans,unordered_set<int> &st,vector<int>&v) {
        for(int x : v) {
            if(!st.count(x)) {
                ans.push_back(x);
                st.insert(x);
            }
        }
    }
    
    vector<vector<int>> findDifference(vector<int>& v1, vector<int>& v2) {
        vector<vector<int>> ans(2);
        unordered_set<int> st1(v1.begin(),v1.end()),st2(v2.begin(),v2.end());
        func(ans[0],st2,v1);
        func(ans[1],st1,v2);
        return ans;
        
    }
};