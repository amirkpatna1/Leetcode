class Solution {
public:
    int trap(vector<int>& v) {
        int n=v.size(),currLeftMax=0,currRightMax=0,l=0,r=n-1,ans=0;
        while(r>l){
            currLeftMax=max(currLeftMax,v[l]);
            currRightMax=max(currRightMax,v[r]);
            if(currRightMax>=currLeftMax){
                ans+=currLeftMax-v[l];
                l++;
            }
            else{
                ans+=currRightMax-v[r];
                r--;
            }
        }
        return ans;
    }
};