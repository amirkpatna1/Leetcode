class Solution {
public:
    pair<int,int> getTwoIndicesThatSumsUpToTarget(vector<int> nums, int target) {
        unordered_map<int,int>  mp;
        int index = 0;
        for(int num : nums) {
            if(mp.count(target - num)) {
                return {mp[target - num], index};
            }
            mp[num] = index;
            index += 1;
        }
        return {-1,-1};
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        pair<int,int> ans = getTwoIndicesThatSumsUpToTarget(nums,target);
        return {ans.first,ans.second};
    }
};