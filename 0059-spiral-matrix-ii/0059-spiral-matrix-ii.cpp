class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n));
        int p=0,q=0,r=n,s=n,k=1;
        for(;k<=n*n;){
            for(int j=p;j<r;j++)v[q][j]=k++;
            q++;
            for(int idx=q;idx<s;idx++)v[idx][r-1]=k++;
            r--;
            for(int j=r-1;j>=p;j--)v[s-1][j]=k++;
            s--;
            for(int idx=s-1;idx>=q;idx--)v[idx][p]=k++;
            p++;
        }
        return v;
    }
};