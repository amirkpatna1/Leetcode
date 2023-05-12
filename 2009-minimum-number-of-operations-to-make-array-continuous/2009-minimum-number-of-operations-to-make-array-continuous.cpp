class Solution {
public:
    int minOperations(vector<int>& v) {
        int n = v.size();
        sort(v.begin(),v.end());
        int p = unique(v.begin(),v.end()) - v.begin();
        v.resize(p);
        int start = 0,end = 0,ans = 0,cnt = 0;
        for(end = 0; end < v.size(); end += 1) {
            cnt += 1;
            while(start < end && v[start] < v[end] - n + 1) {
                cnt -= 1;
                start += 1;
            }
            ans = max(ans,cnt);
        }
        return n - ans;
    }
};