/*
[LeetCode] 75. Sort Colors
https://leetcode.com/problems/sort-colors/
*/

class Solution {
    public void sortColors(int[] nums) {
        int[] counter = new int[3];
        Arrays.stream(nums).forEach(n -> counter[n]++);
        int idx = 0;
        for (int i=0;i<counter.length;i++) {
            for (int j=0;j<counter[i];j++) {
                nums[idx++] = i;
            }
        }
    }
}
