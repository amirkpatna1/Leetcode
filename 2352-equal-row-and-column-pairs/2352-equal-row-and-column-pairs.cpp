class Solution {
public:
    int equalPairs(vector<vector<int>>& v) {
        int n=v.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                bool flag=true;
                for(int k=0;k<n;k++){
                    if(v[i][k]!=v[k][j]){
                        flag=false;break;
                    }
                }
                ans+=flag;
            }
        }
        return ans;
    }
};