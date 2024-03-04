class Solution {
public:
    // 
    
    int bagOfTokensScore(vector<int>& v, int p) {
        sort(v.begin(), v.end());
        int n = v.size();
        int l = 0, r = n - 1;
        int score = 0, ans = 0;
        while(r >= l) {
            if(p >= v[l]) {
                p -= v[l++];
                score += 1;
            } else if(score > 0) {
                p += v[r--];
                score -= 1;
            } else break;
            ans = max(ans, score);
        }
        return ans;
    }
};