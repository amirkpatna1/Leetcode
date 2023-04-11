class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(char c:s){
            if(c=='*' && !ans.empty())ans.pop_back();
            else if(c!='*')ans.push_back(c);
        }
        return ans;
    }
};