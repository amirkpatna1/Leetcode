class Solution {
    public int minIncrementForUnique(int[] v) {
        Arrays.sort(v);
        int n = v.length;
        int curr = v[0];
        int ans = 0;
        for(int i = 1; i < n; i += 1) {
            ans += Math.max(curr - v[i] + 1, 0);
            curr += 1;
            if(v[i] > curr) curr = v[i];
            
        }
        return ans;
    }
}


// 1 1 2 2 3 7

//
