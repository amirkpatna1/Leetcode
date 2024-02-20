class Solution {
public:
    typedef long long ll;
    int missingNumber(vector<int>& v) {
        ll s=accumulate(v.begin(),v.end(),0LL);
        int n=v.size();
        ll ss=n*(n+1LL)/2LL;
        return ss-s;
    }
};