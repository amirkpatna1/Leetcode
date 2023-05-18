class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> indegree(n);
        for(vector<int> &edge : edges) {
            indegree[edge[1]] = true;
        }
        vector<int> ans;
        for(int i = 0; i < n; i += 1) {
            if(!indegree[i]) ans.push_back(i);
        }
        return ans;
    }
};