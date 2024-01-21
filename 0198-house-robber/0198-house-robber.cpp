class Solution {
public:
    //dp[i][0]  ---> max value after skipping i th house
    // dp[i][1] ---> max value after robbing ith house
    int rob(vector<int>& v) {
        int a=0,b=0;
        for(int i=0;i<v.size();i++){
            if(i&1) a=max(b,a+v[i]);
            else b=max(a,b+v[i]);
        }
        return max(a,b);
    }
};