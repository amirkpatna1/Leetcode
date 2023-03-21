class Solution {
public:
    typedef long long ll;
    long long zeroFilledSubarray(vector<int>& v) {
        ll cnt=0,ans=0;
        for(int x:v){
            if(x==0)cnt++;
            else ans+=cnt*(cnt+1LL)/2,cnt=0;
        }
        return ans+cnt*(cnt+1LL)/2;
    }
};