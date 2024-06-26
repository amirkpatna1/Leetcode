class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = *max_element(candies.begin(),candies.end());
        vector<bool> ans;
        for(int candy : candies) {
            if(candy + extraCandies >= maxCandies) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};