class Solution {
public:
    int ans;
    void func(vector<int> &v,vector<int> &vv,int i){
        if(i==v.size()){
            ans=min(ans,*max_element(vv.begin(),vv.end()));
            return ;
        }
        for(int j=0;j<vv.size();j++){
            vv[j]+=v[i];
            func(v,vv,i+1);
            vv[j]-=v[i];
        }
    }
    
    int distributeCookies(vector<int>& v, int k) {
        ans=1e9;
        vector<int> vv(k);
        func(v,vv,0);
        return ans;
    }
};