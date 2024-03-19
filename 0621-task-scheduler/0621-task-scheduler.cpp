class Solution {
public:
    int leastInterval(vector<char>& v, int n) {
        vector<int> freq(26);
        int mx=0;
        for(char c:v){
            freq[c-'A']++;
            mx=max(mx,freq[c-'A']);
        }
        
        int ans=mx+n*(mx-1);
        for(int x:freq)ans+=x==mx;
        return max(ans-1,(int)v.size());
    }
};