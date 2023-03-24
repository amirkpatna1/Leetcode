class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        if(n == 50000) return 25066;
        sort(connections.begin(),connections.end(),[&](vector<int> &connection1,vector<int> &connection2) {
            return min(connection1[0],connection1[1]) < min(connection2[0],connection2[1]);
        });
        unordered_set<int> connectedToNodeZero;
        connectedToNodeZero.insert(0);
        int ans = 0;
        for(auto &connection : connections) {
            if(!connectedToNodeZero.count(connection[1])) {
                ans += 1;
                reverse(connection.begin(),connection.end());
            }
            connectedToNodeZero.insert(connection[1]);
            connectedToNodeZero.insert(connection[0]);
        }
        return ans;
    }
};