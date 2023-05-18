class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,int> indegree;
        for(vector<int> &edge : edges) {
            indegree[edge[1]]++;
        }
        vector<int> ans;
        for(int i = 0; i < n; i += 1) {
            if(!indegree.count(i)) ans.push_back(i);
        }
        return ans;
    }
};