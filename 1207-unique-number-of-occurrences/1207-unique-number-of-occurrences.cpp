class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        unordered_set<int> st;
        for(int x:arr) {
            mp[x]++;
        }
        for(auto it:mp) {
            if(st.count(it.second)) return false;
            st.insert(it.second);
        }
        return true;
    }
};