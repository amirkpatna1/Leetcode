class Solution {
public:
    int mod = 1e9 + 7;
    int exp(long a, long b) {
        int res = 1;
        while(b) {
            if(b & 1) res = (res * a) % mod;
            a =  (a * a) % mod;
            b >>= 1;
        }
        return res;
    }
    // 3, 3
    // 9, 1
    // 9 * 9
    //
    int dp[101][101][101];
    int func(vector<int> &v, int i, int k, int cnt) {
        int n = v.size();
        if(k < 0) return 0;
        if(i >= n) {
            return k == 0 ? exp(2, n - cnt) : 0;
        }
        if(dp[i][k][cnt] != -1) return dp[i][k][cnt];
        return dp[i][k][cnt] = (func(v, i + 1, k, cnt) + func(v, i + 1, k - v[i], cnt + 1)) % mod;
    }
    
    int sumOfPower(vector<int>& v, int k) {
        memset(dp, -1, sizeof(dp));
        return func(v, 0, k, 0);
    }
};