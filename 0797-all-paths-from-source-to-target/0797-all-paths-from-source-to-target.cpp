class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<pair<int, vector<int>>> q;
        int n = graph.size();
        q.push({0, {0}});
        vector<vector<int>> ans;
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            int curr = p.first;
            vector<int> res = p.second;
            if(curr == n - 1) ans.push_back(res);
            for(int x : graph[curr]) {
                res.push_back(x);
                q.push({x, res});
                res.pop_back();
            }
        }
        return ans;
    }
};