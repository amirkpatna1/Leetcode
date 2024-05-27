class Solution {
public:
    int specialArray(vector<int>& v) {
        sort(v.rbegin(), v.rend());
        int ans = -1;
        for(int i = 0; i < v.size(); i += 1) {
            if((i + 1 == v.size() || i + 1 > v[i + 1]) && i + 1 <= v[i]) ans = i + 1;
        }
        return ans;
        
    }
};