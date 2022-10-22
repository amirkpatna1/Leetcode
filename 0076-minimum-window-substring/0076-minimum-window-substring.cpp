class Solution {
public:
    
    bool check(vector<int> &v){
        for(int x:v){
            if(x>0)return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        vector<int> v(128);
        for(char c:t)v[c]++;
        int start=0,end=0,ans=0,idx=0,cnt=t.size(),n=s.length(),size=1e9;
        while(end<n){
            v[s[end++]]--;
            while(check(v)){
                v[s[start++]]++;
                if(end-start<size){
                    idx=start;
                    size=end-start;
                }
            }
        }
        return size==1e9?"":s.substr(idx-1,size+1);
    }
};