class Solution {
public:
    int maximizeGreatness(vector<int>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        int ans = 0;
        for(int i = 0; i < n; i += 1) {
            if(v[i] > v[ans]) ans += 1;
        }
        return ans;
    }
};