class Solution {
public:
    // i --> row
    // n --> row
    // j --> column
    // m --> column
    vector<int> spiralOrder(vector<vector<int>>& v) {
        vector<int> ans;
        int n=v.size()-1,m=v[0].size()-1,i=0,j=0;
        while(i<=n && j<=m){
            for(int k=j;k<=m;k++){
                ans.push_back(v[i][k]);
            }
            if(++i>n)return ans;
            for(int k=i;k<=n;k++){
                ans.push_back(v[k][m]);
            }
            if(--m<j)return ans;
            for(int k=m;k>=j;k--){
                ans.push_back(v[n][k]);
            }
            if(--n<i)return ans;
            for(int k=n;k>=i;k--){
                ans.push_back(v[k][j]);
            }
            if(++j>m)return ans;
            // if(i==n && j==m) return ans;
        }
        // while(ans.size()>(v.size()*v[0].size()))ans.pop_back();
        return ans;
    }
};