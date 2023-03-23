class Solution {
public:
    void dfs(vector<vector<int>> &graph,int currNode,vector<bool> &vis) {
        vis[currNode] = true;
        for(int nextNode : graph[currNode]) {
            if(!vis[nextNode]) dfs(graph,nextNode,vis);
        }
    }
    
    int getNumberOfDisconnectedComponents(int n, vector<vector<int>> &graph) {
        vector<bool> vis(n);
        int numberOfDisconnectedComponents = 0;
        for(int i = 0; i < n; i += 1) {
            if(!vis[i]) {
                numberOfDisconnectedComponents += 1;
                dfs(graph,i,vis);
            }
        }
        return numberOfDisconnectedComponents;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        if(connections.size() < n - 1) return -1;
        for(auto connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }
        int numberOfDisconnectedComponents = getNumberOfDisconnectedComponents(n, graph);
        return numberOfDisconnectedComponents - 1;
    }
};