class Solution {
public:
    typedef long long ll;
    ll dfs(vector<vector<int>> &graph,int i,vector<int> &vis){
        vis[i]=1;
        ll mx=0;
        for(auto x:graph[i]){
            if(!vis[x])mx += 1LL+dfs(graph,x,vis);
        }
        return mx;
    }
    long long countPairs(int n, vector<vector<int>>& v) {
        vector<vector<int>> graph(n);
        for(auto vv:v){
            graph[vv[0]].push_back(vv[1]);
            graph[vv[1]].push_back(vv[0]);
        }
        vector<int> vis(n);
        ll ans=0,k=0;
        for(int i = 0;i < n;i += 1){
            ll val=0;
            if(!vis[i]){
                val=1 + dfs(graph,i,vis);
                // cout<<val<<" ";
                ll cnt = 0;
                k += val;
                ans += (n*1LL-k)*val;
            }
            
        }
        return ans;
    }
};