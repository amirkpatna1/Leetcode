class Solution {
    public boolean checkSubarraySum(int[] v, int k) {
        // i will maintain a prefix sum
        // what i will subtract from that sum so that it becomes multiple of k
        int s = v[0];
        Set<Integer> st = new HashSet<>();
        st.add(0);
        for(int i = 1; i < v.length; i += 1) {
            s += v[i];
            int rem = s % k;
            if(st.contains(rem)) return true;
            st.add((s - v[i]) % k);
        }
        return false;
    }
}