class Solution {
public:
    typedef long long ll;
    long long maximumImportance(int n, vector<vector<int>>& v) {
        vector<int> deg(n),idx(n);
        for(int i=0;i<n;i++)idx[i]=i;
        for(auto &vv:v){
            deg[vv[0]]++,deg[vv[1]]++;
        }
        sort(idx.begin(),idx.end(),[&](int i,int j){
            return deg[i]>deg[j];
        });
        vector<int> val(n);
        for(int i:idx){
            val[i]=n--;
        }
        ll ans=0;
        for(auto &vv:v){
            ans+=val[vv[0]],ans+=val[vv[1]];
        }
        return ans;
    }
};