class Solution {
public:
    int maxFrequencyElements(vector<int>& v) {
        vector<int> u(101);
        int mx = 0, ans = 0;
        for(int x : v) {
            u[x] += 1;
            mx = max(mx, u[x]);
        }
        for(int x : v) {
            if(u[x] == mx) ans += 1;
        }
        return ans;
    }
};