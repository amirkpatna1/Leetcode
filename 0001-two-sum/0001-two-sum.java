class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer,Integer> mp = new HashMap<Integer,Integer>();
        int[] ans = new int[2];
        for(int i = 0; i < nums.length; i += 1) {
            if(mp.containsKey(target - nums[i])) {
                ans[0] = mp.get(target - nums[i]);
                ans[1] = i;
            }
            mp.put(nums[i],i);
        }
        return ans;
    }
}