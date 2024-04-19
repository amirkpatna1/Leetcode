class Solution {
public:
    void dfs(vector<vector<char>> &v,int p,int q,int n,int m){
        if(p<0 || p>=n || q<0 || q>=m || v[p][q]=='0')
            return;
        v[p][q]='0';
        static int x[] = { -1, 1, 0, 0 };
        static int y[] = { 0, 0, -1, 1 };
        for(int i=0;i<4;i++){
            dfs(v,p+x[i],q+y[i],n,m);
        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j,n,m);
                }
            }
        }
        return ans;
    }
};