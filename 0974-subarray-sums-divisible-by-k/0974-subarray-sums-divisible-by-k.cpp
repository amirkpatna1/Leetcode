class Solution {
public:
    int subarraysDivByK(vector<int>& v, int k) {
        int s = 0,ans = 0;
        vector<int> mp(k);
        mp[0] = 1;
        for(int x : v) {
            s = (((s+x)%k)+k)%k;
            ans += mp[s]++;
        }
        return ans;
    }
};