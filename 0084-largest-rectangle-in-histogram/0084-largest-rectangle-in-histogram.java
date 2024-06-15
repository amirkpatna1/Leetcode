class Solution {
    public int largestRectangleArea(int[] v) {
        int n = v.length;
        int[] vl = new int[n];
        int[] vr = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < n; i += 1) {
            while(!st.isEmpty() && v[i] < v[st.peek()]) {
                vr[st.pop()] = i;
            }
            st.push(i);
        }
        while(!st.isEmpty()) vr[st.pop()] = n;
        for(int i = n - 1; i >= 0; i -= 1) {
            while(!st.isEmpty() && v[i] < v[st.peek()]) {
                vl[st.pop()] = i;
            }
            st.push(i);
        }
        while(!st.isEmpty()) vl[st.pop()] = -1;
        
        int ans = 0;
        for(int i = 0; i < n; i += 1) {
            ans = Math.max(ans, (vr[i] - vl[i] - 1) * v[i]);
        }
        return ans;
        
    }
}