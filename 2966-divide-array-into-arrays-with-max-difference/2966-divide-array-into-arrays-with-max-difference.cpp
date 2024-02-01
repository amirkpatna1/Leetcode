class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        int n = v.size();
        for(int i = 0; i + 2 < n; i += 3) {
            if(v[i + 2] - v[i] <= k) ans.push_back({v[i], v[i + 1], v[i + 2]});
            else return {};
        }
        return ans;
    }
};