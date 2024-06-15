class Solution {
    
    class Pair {
        int a, b;
        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
    
    public int[] maxSlidingWindow(int[] v, int k) {
        // Deque<Integer> dq = new ArrayDeque<>();
        Queue<Pair> pq = new PriorityQueue<>((Pair a, Pair b) -> b.a - a.a);
        for(int i = 0; i < k - 1; i += 1) pq.add(new Pair(v[i], i));
        int n = v.length;
        int[] ans = new int[n - k + 1];
        int idx = 0;
        for(int i = k - 1; i < n; i += 1) {
            pq.add(new Pair(v[i], i));
            while(!pq.isEmpty() && pq.peek().b <= i - k) pq.poll();
            ans[idx++] = pq.peek().a;
        }
        
        return ans;
    }
}