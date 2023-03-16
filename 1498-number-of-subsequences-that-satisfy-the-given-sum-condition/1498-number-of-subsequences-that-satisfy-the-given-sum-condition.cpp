



class Solution {
public:
    int mod = (int)1e9 + 7;
    void getAllPowOfTwos(vector<int> &u) {
        int currPow = 1;
        u.push_back(1);
        for(int i = 1; i <= 100001; i += 1) {
            currPow = (currPow * 2) % mod;
            u.push_back(currPow);
        }
    }
    int numSubseq(vector<int>& v, int target) {
        vector<int> u;
        getAllPowOfTwos(u);
        sort(v.begin(),v.end());
        int ans = 0;
        int l = 0,r = v.size() - 1;
        while(r >= l) {
            int s = v[l] + v[r];
            if(s > target) r -= 1;
            else {
                ans = (ans + u[r - l]) % mod;
                l += 1;
            }
        }
        return ans;
    }
};