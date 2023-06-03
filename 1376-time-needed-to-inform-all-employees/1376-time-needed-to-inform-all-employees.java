class Solution {
    
    private int dfs(int i,List<List<Integer>> graph,int[] informTime) {
        int ans = 0;
        for(int x : graph.get(i)) {
            ans = Math.max(ans,informTime[i] + dfs(x,graph,informTime));
        }
        return ans;
    }
    
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        List<List<Integer>> graph = new ArrayList<List<Integer>>();
        for(int i = 0; i < manager.length; i += 1) {
            graph.add(new ArrayList<Integer>());
        }
        for(int i = 0; i < manager.length; i += 1) {
            if(manager[i] != -1) {
                graph.get(manager[i]).add(i);
            }
        }
        return dfs(headID,graph,informTime);
    }
}