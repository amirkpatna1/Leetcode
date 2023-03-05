class Solution {
public:
    int minJumps(vector<int>& v) {
        unordered_map<int,vector<int>> mp;
        int n=v.size();
        if(n==1)return 0;
        for(int i=0;i<n;i++){
            mp[v[i]].push_back(i);
        }
        if(mp.size()==1)return 1;
        vector<int> vis(n);
        vis[0]=1;
        queue<int> q;
        q.push(0);
        int ans=0;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int i=q.front();
                q.pop();
                if(i==n-1)return ans;
                auto &vs=mp[v[i]];
                vs.push_back(i-1);
                vs.push_back(i+1);
                for(int x:vs){
                    if(x>=0 && x<n && !vis[x])q.push(x),vis[x]=1;
                }
                vs.clear();
            }
            ans++;
        }
        return 0;
    }
};