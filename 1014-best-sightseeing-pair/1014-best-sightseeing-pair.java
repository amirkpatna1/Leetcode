class Solution {
    public int maxScoreSightseeingPair(int[] v) {
        int mx = v[0];
        int ans = 0;
        for(int i = 1; i < v.length; i += 1) {
            ans = Math.max(ans, mx + v[i] - i);
            mx = Math.max(mx, v[i] + i);
        }
        return ans;
        
    }
}