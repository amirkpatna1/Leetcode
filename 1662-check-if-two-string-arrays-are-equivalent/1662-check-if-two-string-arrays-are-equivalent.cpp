class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0,j=0;
        int n=word1.size(),m=word2.size();
        int p=0,q=0;
        while(i<n && j<m){
            if(word1[i].size()==p)p=0,i++;
            else if(word2[j].size()==q)q=0,j++;
            else if(word1[i][p++]!=word2[j][q++])return false;
        }
        return (i==n || (i==n-1 && p==word1[i].size())) && (j==m || (j==m-1 && q==word2[j].size()));
    }
};