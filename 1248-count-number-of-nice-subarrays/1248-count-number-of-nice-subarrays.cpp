class Solution {
public:
    int solve(vector<int>&v,int k){
        int n=v.size(),end=0,start=0,ans=0;
        while(end<n){
            k-=(v[end++]&1);
            while(k<0){
                k+=(v[start++]&1);
            }
            ans+=end-start+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& v, int k) {
        return solve(v,k)-solve(v,k-1);
    }
};