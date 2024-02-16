class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& v, int k) {
        unordered_map<int,int> mp;
        for(int x:v)mp[x]++;
        int idx=unique(v.begin(),v.end())-v.begin();
        v.resize(idx);
        sort(v.begin(),v.end(),[&](int &x,int &y){
           if(mp[x]==mp[y])return x<y;
            return mp[x]<mp[y];
        });
        for(int x:v){
            if(k>=mp[x]){
                k-=mp[x];
                mp.erase(x);
            }
            else{
                mp[x]-=k;
                break;
            }
        }
        return mp.size();
    }
};