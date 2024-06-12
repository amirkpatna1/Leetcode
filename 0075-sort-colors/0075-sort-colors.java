class Solution {
    public void sortColors(int[] nums) {
        int i = 0;
        int j = 0;
        int k = nums.length-1;
        while(i <= k){
            if(nums[i] == 1){
                i++;
            } else if(nums[i] == 0){
                swap(nums,i,j);
                i++;
                j++;
            } else{
                swap(nums,i,k);
                k--;
            }
        }
    }

    public void swap(int[] nums, int a, int b){
        int temp = nums[a];
        nums[a]= nums[b];
        nums[b]=temp;
    }
    
}