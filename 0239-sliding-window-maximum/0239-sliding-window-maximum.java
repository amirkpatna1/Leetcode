class Solution {
    
    class Pair {
        int a, b;
        Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
    
    public int[] maxSlidingWindow(int[] v, int k) {
        Deque<Integer> dq = new ArrayDeque<>();
//         Queue<Pair> pq = new PriorityQueue<>((Pair a, Pair b) -> b.a - a.a);
//         for(int i = 0; i < k - 1; i += 1) pq.add(new Pair(v[i], i));
        int n = v.length;
        int[] ans = new int[n - k + 1];
        int idx = 0;
//         for(int i = k - 1; i < n; i += 1) {
//             pq.add(new Pair(v[i], i));
//             while(!pq.isEmpty() && pq.peek().b <= i - k) pq.poll();
//             ans[idx++] = pq.peek().a;
//         }
        
        for(int i = 0; i < n; i += 1) {
            if(!dq.isEmpty() && dq.peekFirst() <= i - k) dq.pollFirst();
            while(!dq.isEmpty() && v[dq.peekLast()] < v[i]) dq.pollLast();
            dq.addLast(i);
            if(i >= k - 1) ans[idx++] = v[dq.peekFirst()];
        }
        return ans;
        
//         TreeMap<Integer, Integer> mp = new TreeMap<>();
//         int start = 0, end = 0;
//         while(end < n) {
//             mp.put(v[end], mp.getOrDefault(v[end++], 0) + 1);
//             if(end - start > k) {
//                 int key = v[start];
//                 int count = mp.get(key);
//                 if(count == 1) mp.remove(key);
//                 else mp.put(v[start], mp.get(key) - 1);
//                 start += 1;
//             }
//             if(end - start == k) ans[idx++] = mp.lastKey();
            
//         }
//         return ans;
    }
}