/*
[LeetCode] 448. Find All Numbers Disappeared in an Array
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
*/
class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> answer = new ArrayList<>();
        boolean[] check = new boolean[nums.length + 1];
        for (int i=0;i<nums.length;i++) {
            check[nums[i]] = true;
        }
        for (int i=1;i<check.length;i++) {
            if (!check[i]) answer.add(i);
        }
        return answer;
    }
}
