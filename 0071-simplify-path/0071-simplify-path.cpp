class Solution {
public:
    string simplifyPath(string s) {
        if(s.back()!='/')s.push_back('/');
        vector<string> v;
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='/'){
                if(ans!="")v.push_back(ans),ans="";
                continue;
            }
            if(s[i]=='.'){
                if(i<n-1){
                    if(s[i+1]=='/')continue;
                    if(s[i+1]=='.'){
                        if(s[i+2]=='/'){
                            ans="";
                            if(!v.empty())v.pop_back();
                            i+=2;
                            continue;
                        }
                        ans="";
                        while(i<n && s[i]!='/'){
                            ans.push_back(s[i]),i++;
                            // cout<<"hi";
                        }
                        v.push_back(ans);
                        ans="";
                    }
                }
                
            }
            // ans="";
            while(s[i]!='/')ans.push_back(s[i]),i++;
            if(ans!="")v.push_back(ans);
            ans="";
        }
        ans="/";
        if(v.empty())return ans;
        for(string ss:v){
            ans+=ss;
            ans.push_back('/');
        }
        ans.pop_back();
        return ans;
    }
};