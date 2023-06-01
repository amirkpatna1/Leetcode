class Solution {
public:
    
    void dfs(vector<vector<int>> &v,int i,int j,int x){
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || (v[i][j]<0 && v[i][j]>x) || v[i][j]==1) return ;
        v[i][j]=x;
        dfs(v,i+1,j,x-1);
        dfs(v,i-1,j,x-1);
        dfs(v,i+1,j+1,x-1);
        dfs(v,i+1,j-1,x-1);
        dfs(v,i,j+1,x-1);
        dfs(v,i,j-1,x-1);
        dfs(v,i-1,j-1,x-1);
        dfs(v,i-1,j+1,x-1);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& v,int step=-1) {
        // dfs(v,0,0,-1);
        // int ans=v.back().back()>0?-1:abs(v.back().back());
        // return ans==0?-1:ans;
        int n=v.size(),m=v[0].size();
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                pair<int,int> p=q.front();
                q.pop();
                int i=p.first,j=p.second;
                if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || v[i][j]<0 || v[i][j]==1) continue;
                if(i==n-1 && j==m-1)return -1*step;
                v[i][j]=step;
                q.push({i+1,j});
                q.push({i-1,j});
                q.push({i+1,j+1});
                q.push({i+1,j-1});
                q.push({i-1,j+1});
                q.push({i-1,j-1});
                q.push({i,j+1});
                q.push({i,j-1});
            }
            step--;
        }
        return -1;
    }
};