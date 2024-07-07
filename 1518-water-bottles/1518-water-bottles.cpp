class Solution {
public:
    int numWaterBottles(int bottles, int k) {
        int ans = 0;
        int rem = 0;
        while(bottles>=k){
            ans += bottles;
            int empty = bottles + rem;
            rem = empty%k;
            bottles = empty/k;
        }
        ans += bottles ;
        rem += bottles;
        ans += rem/k;
        return ans;

    }
};