/*
[LeetCode] 80. Remove Duplicates from Sorted Array II
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
*/
class Solution {
    public int removeDuplicates(int[] nums) {
        int ans = 2;
        if (nums.length < 3) 
            return nums.length;
        for (int i = 2; i < nums.length; i++) {
            if (nums[i] != nums[ans - 2]) {
                nums[ans++] = nums[i];
            }
        }
        return ans;
    }
}
