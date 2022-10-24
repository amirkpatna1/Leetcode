class Solution {
public:
    void func(vector<string> &v,int i,unordered_set<char> &st,int &mask,unordered_set<string> &ans,string &s){
        if(i==v.size()){
            return ;
        }
        for(int j=i;j<v.size();j++){
            if(mask & (1<<j))continue;
            bool flag = false;
            unordered_set<char> dup;
            for(char c:v[j]){
                if(st.count(c) || dup.count(c)){
                    flag = true;break;
                }
                dup.insert(c);
            }
            if(flag)continue;
            mask |= (1<<j);
            s+=v[j];
            for(char c:v[j])st.insert(c);
            ans.insert(s);
            func(v,j+1,st,mask,ans,s);
            mask &= ~(1<<j);
            for(char c:v[j]){
                st.erase(c);
                s.pop_back();
            }
        }
    }
    
    int maxLength(vector<string>& v) {
        unordered_set<string> ans;
        unordered_set<char> st;
        string s;
        int mask = 0;
        func(v,0,st,mask,ans,s);
        int cnt = 0;
        for(string s:ans)cnt = max(cnt,(int)s.size());
        return cnt;
    }
};