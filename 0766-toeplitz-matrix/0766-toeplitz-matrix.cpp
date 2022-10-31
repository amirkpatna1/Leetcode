class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& v) {
        int n=v.size(),m=v[0].size();
        for(int i=0;i<n;i++){
            int t = v[i][0];
            for(int j=0,k=i;j<m && k <n;j++,k++){
                if(t != v[k][j]) return false;
            }
        }
        for(int i=0;i<m;i++){
            int t = v[0][i];
            for(int j=i,k=0;j<m && k <n;j++,k++){
                if(t != v[k][j]) return false;
            }
        }
        return true;
    }
};