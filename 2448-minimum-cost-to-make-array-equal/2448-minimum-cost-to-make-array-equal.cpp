class Solution {
public:
    // 10 , 9
    
    typedef long long ll;
    long long minCost(vector<int>& v, vector<int>& cost) {
        ll s = 0;
        int n=v.size();
        for(int i=0;i<n;i++){
            s+=cost[i];
        }
        s/=2LL;
        ll ss = 0;
        ll val = 1e12;
        
        vector<int> idx(n);
        for(int i=0;i<n;i++)idx[i]=i;
        sort(idx.begin(),idx.end(),[&](int i,int j){
            return v[i]<v[j];
        });
        for(int i=0;i<cost.size();i++) {
            // cout<<v[idx[i]]<<" ";
            if(ss+(ll)cost[idx[i]]>s){
                val = v[idx[i]];break;
            }
            ss+=(ll)cost[idx[i]];
        }
        ll ans = 0;
        // cout<<val<<endl;
        for(int i=0;i<v.size();i++){
            ans+=(ll(abs(v[i]-val))*ll(cost[i]));
        }
        return ans;
    }
};