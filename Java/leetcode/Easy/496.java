/*
[LeetCode] 496. Next Greater Element I
https://leetcode.com/problems/next-greater-element-i/
*/

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int[] answer = new int[nums1.length];
        HashMap<Integer, Integer> map = new HashMap<>();
        Arrays.fill(answer, -1);
        Stack<Integer> st = new Stack<>();
        for (int i=0;i<nums2.length;i++) {
            while (!st.isEmpty() && nums2[st.peek()] < nums2[i]) {
                map.put(nums2[st.pop()], nums2[i]); 
            }
            st.push(i);
        }
        for (int i=0;i<nums1.length;i++) {
            if (map.containsKey(nums1[i]))
                answer[i] = map.get(nums1[i]);
        }
        return answer;
    }
}
