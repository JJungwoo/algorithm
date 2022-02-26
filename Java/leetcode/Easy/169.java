/*
[LeetCode] 169. Majority Element
https://leetcode.com/problems/majority-element/
*/

class Solution {
    public int majorityElement(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        int max = 0;
        int ans = 0;
        for (int n : nums) {
            int val = map.getOrDefault(n, 0) + 1;
            if (max < val) {
                max = val;
                ans = n;
            }
            map.put(n, val);
        }
        return ans;
    }
}
