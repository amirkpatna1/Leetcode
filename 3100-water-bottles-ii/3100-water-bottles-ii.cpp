class Solution {
public:
    int maxBottlesDrunk(int f, int e) {
        int ans = f;
        while(f >= e) {
            f -= e;
            f += 1;
            e += 1;
            ans += 1;
        }
        return ans;
    }
};