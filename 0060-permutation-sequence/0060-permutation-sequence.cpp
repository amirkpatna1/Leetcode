class Solution {
public:
    
    void func(vector<int> &fact,int n){
        fact.push_back(1);
        for(int i=1;i<=n;i++)fact.push_back(fact.back()*i);
    }
    void func(vector<int> &fact,vector<int> &v,string &s,int n,int k){
        if(n==1){
            s.push_back(v.back()+'0');
            return ;
        }
        int p=k/(fact[n-1]);
        
        int rem=k%(fact[n-1]);
        if(rem==0)p--;
        k-=fact[n-1]*p;
        s.push_back(v[p]+'0');
        v.erase(v.begin()+p);
        func(fact,v,s,n-1,k);
    }
    string getPermutation(int n, int k) {
        vector<int> fact;
        func(fact,n);
        // for(int i:fact)cout<<i<<" ";
        string ans;
        vector<int> v;
        for(int i=1;i<=n;i++)v.push_back(i);
        func(fact,v,ans,n,k);
        return ans;
    }
};