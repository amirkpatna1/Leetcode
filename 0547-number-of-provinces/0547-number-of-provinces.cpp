class Solution {
public:
    void func(vector<vector<int>> &v,int i,vector<bool> &vis){
        vis[i]=true;
        for(int j=0;j<v.size();j++){
            if(v[i][j] && !vis[j])func(v,j,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& v) {
        int ans=0;
        int n=v.size();
        vector<bool> vis(n);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans++;
                func(v,i,vis);
            }
        }
        return ans;
    }
};