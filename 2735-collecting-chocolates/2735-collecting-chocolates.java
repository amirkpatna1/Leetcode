class Solution {
    public long minCost(int[] nums, int x) {
        int n = nums.length;
        int[] A = new int[n];
        for(int i = 0; i < n; i += 1) A[i] = Integer.MAX_VALUE;
        long ans = Long.MAX_VALUE;
        for(int i = 0; i < n; i += 1) {
            
            long s = 0;
            for(int j = 0; j < n; j += 1) {
                A[j] = Math.min(A[j], nums[(j + i) % n]);
                s += A[j];
            }
            s += (long)i * (long)x;
            ans = Math.min(ans,s);
        }
        return ans;
    }
}