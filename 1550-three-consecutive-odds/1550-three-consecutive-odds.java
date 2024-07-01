class Solution {
    public boolean threeConsecutiveOdds(int[] arr) {
        
        for(int i = 2; i < arr.length; i += 1) {
            if(arr[i - 2] % 2 == 1 && arr[i - 1] % 2 == 1 && arr[i] % 2 == 1) return true; 
        }
        return false;
        
    }
}