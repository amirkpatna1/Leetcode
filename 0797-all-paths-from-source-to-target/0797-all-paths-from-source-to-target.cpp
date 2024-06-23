class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<vector<int>> q;
        int n = graph.size();
        q.push({0});
        vector<vector<int>> ans;
        while(!q.empty()) {
            vector<int> res = q.front();
            q.pop();
            int curr = res.back();
            if(curr == n - 1) ans.push_back(res);
            for(int x : graph[curr]) {
                res.push_back(x);
                q.push({res});
                res.pop_back();
            }
        }
        return ans;
    }
};