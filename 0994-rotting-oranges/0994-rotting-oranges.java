class Solution {
    
    class Pair {
        int row;
        int col;
        
        Pair(int row, int col) {
            this.row = row;
            this.col = col;
        }
    }
    
    public int orangesRotting(int[][] v) {
        
        Queue<Pair> q = new LinkedList<>();
        
        int n = v.length;
        int m = v[0].length;
        
        int fresh = 0;
        for(int i = 0; i < n; i += 1) {
            for(int j = 0; j < m; j += 1) {
                if(v[i][j] == 1) fresh += 1;
                else if(v[i][j] == 2) q.add(new Pair(i, j));
            }
        }
        if(fresh == 0) return 0;
        int ans = -1;
        int[] dir = {-1, 0, 1, 0, -1};
        while(!q.isEmpty()) {
            int sz = q.size();
            while(sz-- > 0) {
                Pair p = q.poll();
                int i = p.row;
                int j = p.col;
                for(int k = 0; k < 4; k += 1) {
                    int row = i + dir[k];
                    int col = j + dir[k + 1];
                    if(row >= 0 && row < n && col >= 0 && col < m && v[row][col] == 1) {
                        q.add(new Pair(row, col));
                        v[row][col] = 2;
                        fresh -= 1;
                    }
                }
            }
            ans += 1;
        }
        return fresh > 0 ? -1 : ans;
        
    }
}