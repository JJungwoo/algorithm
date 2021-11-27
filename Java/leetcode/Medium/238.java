/*
[LeetCode] 238. Product of Array Except Self
https://leetcode.com/problems/product-of-array-except-self/
*/

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] answer = new int[nums.length];
        int result = 1;
        int zeroCount = 0, nonZeroResult = 1;
        for (int i=0;i<nums.length;i++) {
            if (nums[i] == 0) zeroCount++;
            else nonZeroResult *= nums[i];
            result *= nums[i];
        }
        if (zeroCount > 1) return answer;
        Arrays.fill(answer, result);
        
        for (int i=0;i<nums.length;i++) {
            if (nums[i] == 0) answer[i] = nonZeroResult;
            else answer[i] /= nums[i];
        }
        return answer;
    }
}
