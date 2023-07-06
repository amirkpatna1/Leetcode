class Solution {
public:
    int minSubArrayLen(int target, vector<int>& v) {
        int n=v.size();
        int end=0,start=0,ans=1e9,s=0;
        while(end<n){
            s+=v[end++];
            while(s>=target){
                ans=min(ans,end-start);
                s-=v[start++];
            }
        }
        return ans==1e9?0:ans;
    }
};