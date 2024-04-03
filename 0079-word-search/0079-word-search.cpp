class Solution {
public:
    typedef long long ll;
    
    bool func(vector<vector<char>> &v,string &s,int i,int j,int k){
        if(k==s.length())return true;
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || v[i][j]!=s[k] ) return false;
        char c=v[i][j];
        v[i][j]='*';
        bool ans = func(v,s,i+1,j,k+1) || func(v,s,i,j+1,k+1) ||func(v,s,i-1,j,k+1) || func(v,s,i,j-1,k+1);
        v[i][j]= c;
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& v, string s) {
        int n=v.size(),m=v[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==s[0])
                    if(func(v,s,i,j,0))return true;
            }
        }
        return false;
    }
};