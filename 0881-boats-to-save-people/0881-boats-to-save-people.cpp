class Solution {
public:
    int numRescueBoats(vector<int>& v, int limit) {
        int n=v.size();
        sort(v.rbegin(),v.rend());
        int i=0,j=n-1,ans=0;
        while(j>=i){
            if(v[i]+v[j]<=limit)j--;
            ans++,i++;
        }
        return ans;
    }
};