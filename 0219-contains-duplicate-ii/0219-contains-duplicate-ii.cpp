class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& v, int k) {
        int n=v.size();
        unordered_map<int,int> mp;
        if(k>=n)k=n-1;
        for(int i=0;i<=k;i++){
            if(mp.count(v[i]))return 1;
            mp[v[i]]++;
        }
        for(int i=1;i+k<=n-1;i++){
            mp[v[i-1]]--;
            if(mp[v[i+k]])return 1;
            mp[v[i+k]]++;
        }
        return 0;
    }
};