class Solution {
public:
    int dp[501][501];
    int maxCommonSubseq(vector<int> &v1,vector<int>& v2,int i,int j) {
        if(i == v1.size() || j == v2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(v1[i] == v2[j]) return dp[i][j] = 1 + maxCommonSubseq(v1,v2,i + 1, j + 1);
        return dp[i][j] = max(maxCommonSubseq(v1,v2, i + 1,j),maxCommonSubseq(v1,v2, i, j + 1));
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return maxCommonSubseq(nums1,nums2,0,0);
    }
};