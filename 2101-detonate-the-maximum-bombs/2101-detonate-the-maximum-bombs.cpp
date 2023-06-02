class Solution {
public:
    typedef long long ll;
    void dfs(vector<vector<int>> &v,int i,vector<int> &vis,int &ans){
        vis[i]=1;
        for(int j=0;j<v.size();j++){
            if(!vis[j] && ((ll(v[i][0]-v[j][0])*ll(v[i][0]-v[j][0])+ll(v[i][1]-v[j][1])*ll(v[i][1]-v[j][1])-(ll)v[i][2]*(ll)v[i][2])<=0)){
                ans++;
                dfs(v,j,vis,ans);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& v) {
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int> vis(n);
            if(!vis[i]){
                int res=1;
                dfs(v,i,vis,res);
                ans=max(ans,res);
            }
        }
        return ans;
    }
};