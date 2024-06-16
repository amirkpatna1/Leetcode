class Solution {
    public int minPatches(int[] v, int n) {
        int ans = 0;
        long s = 0;
        Arrays.sort(v);
        
        int i = 0;
        
        while(s < n) {
            if(i < v.length && v[i] > s + 1 || i == v.length) {
                s += (s + 1);
                ans += 1;
            } else if(i < v.length){
                s += v[i++];
            }
        }
        return ans;
        // 1, 3 --> 1 + 3 = 4
        
    }
}