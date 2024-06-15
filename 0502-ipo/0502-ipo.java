class Solution {
    
    class Pair {
        int index;
        int profit;
        Pair(int index, int profit) {
            this.index = index;
            this.profit = profit;
        }
    }
    
    public int findMaximizedCapital(int k, int w, int[] profits, int[] capital) {
        
        int n = capital.length;
        
        Integer[] idx = new Integer[n];
        
        for(int i = 0; i < n; i += 1) idx[i] = i;
        Arrays.sort(idx, (Integer i, Integer j) -> {
            return capital[i] - capital[j];
        });
        
        Queue<Integer> pq = new PriorityQueue<>((Integer a, Integer b) -> b - a);
        
        int prev = 0;
        int ans = 0;
        int i = 0;
        while(k-- > 0) {
            while(i < n && capital[idx[i]] <= w) {
                pq.add(profits[idx[i++]]);
            }
            if(pq.isEmpty()) break;
            int profit = pq.poll();
            w += profit;
        }
        return w;
    }
}