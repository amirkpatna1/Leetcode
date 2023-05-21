class Solution {
public:
    queue<pair<int,int>> q;
    int check(vector<vector<int>> &v,int i,int j,int c){
        if(i<0 || i>=v.size() || j<0 || j>=v[0].size() || v[i][j]==c)return 1;
        return 0;
    }
    void dfs(vector<vector<int>> &v,int i,int j){
        if(check(v,i,j,2) || v[i][j]==0)return ;
        v[i][j]=2;
        q.push({i,j});
        dfs(v,i,j+1);
        dfs(v,i+1,j);
        dfs(v,i,j-1);
        dfs(v,i-1,j);
    }
    int bfs(vector<vector<int>> &v){
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            ans++;
            for(int k=0;k<n;k++){
                pair<int,int> p=q.front();
                int i=p.first;
                int j=p.second;
                q.pop();
                if(!check(v,i,j,3)){
                    if(v[i][j]==1)
                        return ans-2;
                    v[i][j]=3;
                    q.push({i,j+1});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i-1,j});
                }
            }
        }
        return ans;
    }
    int shortestBridge(vector<vector<int>>& v) {
        int flag=0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j]==1){
                    dfs(v,i,j);
                    flag=1;
                    break;
                }
                
            }
            if(flag)break;
        }
        return bfs(v);
    }
};