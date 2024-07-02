class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1);
        Arrays.sort(nums2);
        List<Integer> ans = new ArrayList<>();
        for(int i = 0, j = 0; i < nums1.length && j < nums2.length; ) {
            if(nums1[i] == nums2[j]) {
                ans.add(nums1[i]);
                i += 1;
                j += 1;
            } else if(nums1[i] > nums2[j]) j += 1;
            else i += 1;
        }
        return ans.stream().mapToInt(Integer::intValue).toArray();
    }
}