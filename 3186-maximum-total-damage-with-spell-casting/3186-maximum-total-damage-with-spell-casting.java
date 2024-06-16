class Solution {
    public long maximumTotalDamage(int[] p) {
        Map<Integer, Integer> keyToFreq = new HashMap<>();
        for(int i = 0; i < p.length; i += 1) {
            keyToFreq.put(p[i], keyToFreq.getOrDefault(p[i], 0) + 1);
        }
        int n = keyToFreq.size();
        int[] v = new int[n];
        int idx = 0;
        for(Integer key : keyToFreq.keySet()) {
            v[idx++] = key;
        }
        Arrays.sort(v);
        
        // dp[i] --> max damage after i th index
        long[] dp = new long[n];
        
        for(int i = 0; i < n; i += 1) {
            long temp = 0;
            for(int j = Math.max(i - 6, 0); j < i; j += 1) {
                if(v[i] - v[j] > 2)
                    temp = Math.max(temp, dp[j]);
            }
            dp[i] = (long)v[i] * (long)keyToFreq.get(v[i]) + temp;
            
        }

        // [7,1,6,6] --> 1, 6, 7
        // [5,9,2,10,2,7,10,9,3,8] --> 2, 3, 5, 7, 8, 9, 10
        // 4, 3, 5, 
        
        return Arrays.stream(dp).max().orElseThrow();
    }
}