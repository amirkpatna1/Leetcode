class Solution {
    public int[][] merge(int[][] v) {
        int n = v.length;
        Arrays.sort(v, (int[] a, int[] b) -> {
            if(a[0] == b[0]) return a[1] - b[1];
            return a[0] - b[0];
        });
        int start = v[0][0];
        int end = v[0][1];
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        for(int i = 1; i < n; i += 1) {
            if(v[i][0] <= end) end = Math.max(end, v[i][1]);
            else {
                ans.add(Arrays.asList(start, end));
                start = v[i][0];
                end = v[i][1];
            }
        }
        ans.add(Arrays.asList(start, end));
        n = ans.size();
        int[][] res = new int[n][2];
        for(int i = 0; i < n; i += 1) {
            res[i][0] = ans.get(i).get(0); 
            res[i][1] = ans.get(i).get(1);
        }
        return res;
    }
}