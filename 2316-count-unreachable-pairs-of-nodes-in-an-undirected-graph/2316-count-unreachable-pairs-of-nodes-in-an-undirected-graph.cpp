typedef long long ll;
class Solution {
public:
    
    void countNodes(vector<vector<int>> &graph,int currNode,vector<bool> &vis,int &count) {
        vis[currNode] = true;
        for(int x : graph[currNode]) {
            if(!vis[x]) {
                count += 1;
                countNodes(graph,x,vis,count);
            }
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n);
        vector<int> res;
        for(int i = 0; i < n; i += 1) {
            int count = 0;
            if(!vis[i]) {
                countNodes(graph,i,vis,count);
                res.push_back(count + 1);
            }
        }
        n = res.size();
        if(n == 1) return 0;
        vector<ll> temp(n);
        // for(int x : res) cout<<x<<' ';
        for(int i = 1; i < n; i += 1) temp[i] += (temp[i - 1] + res[i - 1]);
        ll k = res.back();
        for(int i = n - 2; i >= 0; i -= 1) {
            temp[i] = temp[i] + k;
            k += res[i];
        }
        
        ll ans = 1;
        for(int i = 0; i < n; i += 1) {
            ans += (ll)(res[i] * temp[i]);
        }
        return ans/2LL;
    }
};