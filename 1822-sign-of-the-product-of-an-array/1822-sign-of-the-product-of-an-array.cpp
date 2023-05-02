class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool ans = true;
        for(int x : nums) {
            if(x == 0) return 0;
            if(x < 0) ans = !ans;
        }
        return ans ? ans : -1;
    }
};