class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int m) {
        int n=v.size();
        if(!m)return true;
        if(n==1 && v[0]==0 && m==1)return true;
        for(int i=0;i<n && m;i++){
            if(i==0 && !v[i] && !v[i+1])v[i]=1,m--;
            else if(i==n-1 && !v[i] && !v[i-1])v[i]=1,m--;
            else if(i>0 && i<n-1 && v[i-1]==0 && v[i]==0 && v[i+1]==0)v[i]=1,m--;
        }
        return m==0;
    }
};