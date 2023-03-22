class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto &edge : roads) {
            graph[edge[0]-1].push_back({edge[1] - 1,edge[2]});
            graph[edge[1]-1].push_back({edge[0] - 1,edge[2]});
        }
        int ans = 1e9;
        queue<pair<int,int>> q;
        vector<bool> visited(n);
        q.push({0,1e9});
        while(!q.empty()) {
            pair<int,int> currNode = q.front();
            q.pop();
            if(visited[currNode.first]) continue;
            visited[currNode.first] = true;
            ans = min(ans,currNode.second);
            for(auto connectedNodes : graph[currNode.first]) {
                if(!visited[connectedNodes.first])q.push({connectedNodes.first,min(currNode.second,connectedNodes.second)});
                else ans = min(ans,connectedNodes.second);
            }
        }
        return ans;
    }
};