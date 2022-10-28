class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for(string s:v){
            string ss=s;
            sort(ss.begin(),ss.end());
            mp[ss].push_back(s);
        }
        for(auto it:mp)ans.push_back(it.second);
        return ans;
    }
};