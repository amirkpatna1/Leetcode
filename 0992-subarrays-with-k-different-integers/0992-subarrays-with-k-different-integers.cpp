class Solution {
public:
    
    int func(vector<int> &v,int k){
        int n=v.size(),start=0,end=0,ans=0;
        unordered_map<int,int> mp;
        while(end<n){
            mp[v[end++]]++;
            while(mp.size()>k){
                if(mp[v[start]]==1)mp.erase(v[start]);
                else mp[v[start]]--;
                start++;
            }
            ans+=end-start;
        }
        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& v, int k) {
        // <=3,<=2
        return func(v,k)-func(v,k-1);
    }
};