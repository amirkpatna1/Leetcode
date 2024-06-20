class Solution {
private:
    bool helper(vector<int> &v,int m,int k){
        int prev=v[0];
        for(int i=1;i<v.size();i++){
            if(v[i]-prev>=m){
                k-=1;
                prev=v[i];
            }
        }
        return k-1<=0;
    }
public:
    int maxDistance(vector<int>& v, int k) {
        sort(v.begin(),v.end());
        int l=0,r=0,ans=0;
        for(int i=1;i<v.size();i++)l=min(l,v[i]-v[i-1]);
        r=v.back()-v[0];
        while(r>=l){
            int m=(l+r)/2;
            // cout<<m<<" ";
            if(helper(v,m,k)){
                ans=m;
                l=m+1;
            }
            else r=m-1;
        }
        return ans;
    }
};