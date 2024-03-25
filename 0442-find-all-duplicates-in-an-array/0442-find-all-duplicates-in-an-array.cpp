class Solution {
public:
    vector<int> findDuplicates(vector<int>& v) {
        int n = v.size();
        vector<int> ans;
        for(int i = 0; i < n; i += 1) {
            int j = abs(v[i]) - 1;
            if(v[j] < 0) ans.push_back(abs(v[i]));
            else v[j] *= -1;
        }
        return ans;
    }
};