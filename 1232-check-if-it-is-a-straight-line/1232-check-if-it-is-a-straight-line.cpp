class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) {
        int gcd = __gcd(v[0][0] - v[1][0],v[0][1] - v[1][1]);
        pair<int,int> slope = {(v[0][0] - v[1][0])/gcd,(v[0][1] - v[1][1])/gcd};
        if(slope.first * slope.second < 0) {
            slope.first *= slope.first < 0 ? 1 : -1;
            slope.second *= slope.second < 0 ? -1 : 1;
        }
        for(int i = 1; i < v.size(); i += 1) {
            int currGcd = __gcd(v[i - 1][0] - v[i][0],v[i - 1][1] - v[i][1]);
            pair<int,int> currSlope = {(v[i - 1][0] - v[i][0])/currGcd,(v[i - 1][1] - v[i][1])/currGcd};
            if(currSlope.first * currSlope.second < 0) {
                currSlope.first *= currSlope.first < 0 ? 1 : -1;
                currSlope.second *= currSlope.second < 0 ? -1 : 1;
            }
            if((slope.first == currSlope.first && slope.first == 0) || (slope.second == currSlope.second && slope.second == 0)) continue;
            if(slope != currSlope) return false;
            
        }
        return true;
    }
};