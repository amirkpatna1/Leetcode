class Solution {
public:
    int dfs(vector<vector<pair<int,int>>> &graph,int i,int j,int k,vector<vector<int>> &dp){
        if(i==j)return 0;
        if(k==-1)return 1e9;
        if(dp[i][k]!=-1)return dp[i][k];
        int mn=1e9;
        for(auto &x:graph[i]){
            mn=min(mn,x.second+dfs(graph,x.first,j,k-1,dp));
        }
        return dp[i][k]=mn;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& v, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto vv:v){
            graph[vv[0]].push_back({vv[1],vv[2]});
        }
        vector<vector<int>> vis(n,vector<int>(k+1,-1));
        int ans=dfs(graph,src,dst,k,vis);
        return ans>=1e9?-1:ans;
    }
};