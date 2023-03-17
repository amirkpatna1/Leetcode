class Solution {
    public int numSubseq(int[] v, int target) {
        Arrays.sort(v);
        int[] pow2 = new int[100001];
        int mod = (int)1e9+7;
        pow2[0] = 1;
        for(int i = 1; i < 100001; i += 1) {
            pow2[i] = (pow2[i - 1] * 2) % mod;
        }
        int l = 0,r = v.length - 1,ans = 0;
        while(r >= l) {
            if(v[l] + v[r] > target) r -= 1;
            else {
                ans = (ans + pow2[r - l]) % mod;
                l += 1;
            }
        }
        return ans;
    }
}