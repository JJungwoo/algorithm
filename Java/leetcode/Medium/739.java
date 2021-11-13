/*
[LeetCode] 739. Daily Temperatures
https://leetcode.com/problems/daily-temperatures/
*/

class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int[] answer = new int[temperatures.length];
        Stack<Integer> st = new Stack<>();
        for (int i=0;i<temperatures.length;i++) {
            while (!st.empty() && temperatures[st.peek()] < temperatures[i]) {
                int cur = st.pop();
                answer[cur] = i - cur;
            }
            st.push(i);
        }
        return answer;
    }
}
