class Solution {
public:
    
    void lis(vector<int> &v,vector<int> &ans) {
        vector<int> res;
        for(int x : v) {
            auto it = upper_bound(res.begin(),res.end(),x);
            if(it != res.end()) {
                *it = x;
                ans.push_back(it - res.begin() + 1);
            }
            else {
                res.push_back(x);
                ans.push_back(res.size());
            }
        }
    }
    
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& v) {
        vector<int> ans;
        lis(v,ans);
        return ans;
    }
};