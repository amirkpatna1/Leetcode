class Solution {
public:
    
    void dfs(vector<string> &ans,string res,int open,int close) {
        if(open == close && open == 0) {
            ans.push_back(res);
            return ;
        }
        if(open > 0) dfs(ans,res + "(",open - 1,close);
        if(close > open)dfs(ans,res + ")",open,close - 1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;
        dfs(ans,res,n,n);
        return ans;
    }
};