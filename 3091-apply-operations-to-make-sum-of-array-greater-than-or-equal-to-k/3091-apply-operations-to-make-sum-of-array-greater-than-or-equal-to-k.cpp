class Solution {
public:
    int minOperations(int k) {
        int freq = 1;
        int ans = 1e9;
        int curr = 1;
        while(curr < k) {
            ans = min(ans, curr - 1 + (k - 1) / curr);
            curr += 1;
        }
        
        return ans == 1e9 ? 0 : ans;
    }
};