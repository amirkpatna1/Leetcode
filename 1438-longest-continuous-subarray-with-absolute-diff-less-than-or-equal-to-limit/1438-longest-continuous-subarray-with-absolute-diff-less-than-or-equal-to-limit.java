class Solution {
    public int longestSubarray(int[] v, int limit) {
        int n = v.length;
        int start = 0, end = 0, ans = 0, cnt = 0;
        TreeMap<Integer, Integer> mp = new TreeMap<>();
        while(end < n) {
            mp.put(v[end], mp.getOrDefault(v[end], 0) + 1);
            end += 1;
            Integer first = mp.firstKey();
            Integer last = mp.lastKey();
            while(Math.abs(first - last) > limit) {
                if(mp.get(v[start]) == 1) {
                    mp.remove(v[start]);
                } else
                    mp.put(v[start], mp.get(v[start]) - 1);
                start += 1;
                
                first = mp.firstKey();
                last = mp.lastKey();
            }
            ans = Math.max(ans, end - start);
        }
        return ans;
    }
}