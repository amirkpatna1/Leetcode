class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mp;
        for(auto match : matches) {
            mp[match[1]]++;
            if(!mp.count(match[0])) mp[match[0]] = 0;
        }
        vector<vector<int>> ans(2);
        for(auto it : mp) {
            if(it.second == 0) ans[0].push_back(it.first);
            else if(it.second == 1) ans[1].push_back(it.first);
        }
        for(int i = 0 ; i < 2 ; i += 1) {
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};