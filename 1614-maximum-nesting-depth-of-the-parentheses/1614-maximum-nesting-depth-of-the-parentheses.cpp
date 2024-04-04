class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, open = 0, close = 0;
        for(char c : s) {
            if(c == '(') open += 1;
            else if(c == ')') open -= 1;
            ans = max(ans, open);
        }
        return ans;
    }
};