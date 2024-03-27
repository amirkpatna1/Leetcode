class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        int cnt=0,n=a.size();
        if(k<=1)
            return 0;
        int prod=1;
        long long s=0;
        int r=0;
        int l=0;
        while(r<n){
            prod*=a[r];
            while(prod>=k){
                prod/=a[l];
                l++;
            }
            s+=r-l+1;
            
            r++;
        }
        return s;
    }
};