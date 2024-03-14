class Solution {
public:
    typedef long long ll;
    int numSubarraysWithSum(vector<int>& v, int goal) {
        unordered_map<ll,ll> mp({{0,1}});
        ll ps=0,ans=0;
        for(int &x:v){
            ps+=x;
            ans+=mp[ps-goal];
            mp[ps]++;
        }
        return (int)ans;
    }
};