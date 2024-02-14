class Solution {
public:
    vector<int> rearrangeArray(vector<int>& v) {
        vector<int> u,t,ans;
        for(auto x:v){
            if(x>=0)u.push_back(x);
            else t.push_back(x);
        }
        int j=0,k=0;
        for(int i=0;i<v.size();i++){
            if(i&1)ans.push_back(t[j++]);
            else ans.push_back(u[k++]);
        }
        return ans;
        
    }
};