class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int o=count(s.begin(),s.end(),'(');
        int c=count(s.begin(),s.end(),')');
        vector<int> v(o+c);
        int i=0;
        stack<int> st;
        for(int j=0;j<s.length();j++){
            if(s[j]=='(')st.push(i),i++;
            else if(s[j]==')'){
                if(!st.empty()){
                    v[st.top()]=1,v[i]=1;
                    st.pop();
                }
                i++;
            }
        }
        
        string ans;
        i=0;
        for(char c:s){
            if(c!='(' && c!=')')ans.push_back(c);
            else if(v[i++])ans.push_back(c);
        }
        return ans;
        
    }
};