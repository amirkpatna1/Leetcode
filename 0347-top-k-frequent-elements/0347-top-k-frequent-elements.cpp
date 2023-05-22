class Solution {
public:
    vector<int> topKFrequent(vector<int>& v, int k) {
        unordered_map<int,int> mp;
        for(int &x:v)mp[x]++;
        sort(v.begin(),v.end(),[&](int x,int y){
            if(mp[x]==mp[y])return x<y;
            return mp[x]>mp[y];
        });
        int n=v.size();
        vector<int> ans;
        for(int i=1;i<n && k;i++){
            if(v[i]!=v[i-1])ans.push_back(v[i-1]),k--;
        }
        if(k>0)ans.push_back(v.back());
        return ans;
    }
};