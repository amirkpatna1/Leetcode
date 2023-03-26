class Solution {
public:
    unordered_map<int,vector<int>> graph;
    int ans=INT_MIN;
    
    void dfs(int s,int u,int dist){
        graph[u][1]=s;
        graph[u][2]=dist++;
        
        int upcoming=graph[u][0];
        if(upcoming!=-1){
            if(graph[upcoming][1]==-1)
                dfs(s,upcoming,dist);
            else if(graph[upcoming][1]==s)
                ans=max(ans,graph[u][2]-graph[upcoming][2]+1);
        }
    }
    
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        for(int i=0;i<n;i++){
            vector<int> v(3,-1);
            v[0]=edges[i];
            graph[i]=v;
        }
        
        for(int i=0;i<n;i++){
            if(graph[i][1]==-1)
                dfs(i,i,0);
        }
        
        return ans == INT_MIN ? -1 : ans;
    }
    
};