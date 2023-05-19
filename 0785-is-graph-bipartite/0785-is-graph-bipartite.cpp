class Solution {
public:
    
    bool dfs(vector<vector<int>> &v,int i,vector<int> &col){
        bool ans=true;
        for(int x:v[i]){
            if(col[x]==col[i])return false;
            if(col[x]==-1){
                col[x]=!col[i];
                ans= ans && dfs(v,x,col);
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& v) {
        int n=v.size();
        vector<int> col(n,-1);
        bool ans=true;
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                col[i]=0;
                ans = ans && dfs(v,i,col);
            }
        }
        return ans;
    }
};