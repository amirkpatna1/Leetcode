class Solution {
public:
    typedef long long ll;
    long long minimumTime(vector<int>& v, int tot) {
        ll gans=1e14,lt=1,rt=1e14;
        while(rt>=lt){
            ll t=(rt+lt)/2;
            ll ans=0;
            for(int x:v){
                ans+=(ll)(t/x);
            }
            if(ans>=tot){
                gans=min(gans,t);
                rt=t-1;
            }
            else lt=t+1;
            
        }
        return gans;
    }
};