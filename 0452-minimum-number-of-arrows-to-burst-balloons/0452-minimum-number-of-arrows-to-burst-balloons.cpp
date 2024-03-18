class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans = 1;
        int start = points[0][0],end = points[0][1];
        for(int i = 1; i < points.size(); i += 1) {
            if(points[i][0] <= end) end = min(end,points[i][1]);
            else end = points[i][1],ans += 1; 
        }
        return ans;
    }
};