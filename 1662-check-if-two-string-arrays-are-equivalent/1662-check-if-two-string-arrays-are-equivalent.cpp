class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s;
        for(string &ss:word1){
            for(char c:ss)s.push_back(c);
        }
        for(int i=word2.size()-1;i>=0;i--){
            for(int j=word2[i].size()-1;j>=0;j--){
                if(s.back() == word2[i][j])s.pop_back();
                else return false;
            }
        }
        return true;
    }
};