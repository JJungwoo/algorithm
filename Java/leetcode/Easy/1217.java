/*
[LeetCode] 1217. Minimum Cost to Move Chips to The Same Position
https://leetcode.com/problems/minimum-cost-to-move-chips-to-the-same-position/
*/

class Solution {
    public int minCostToMoveChips(int[] position) {
        int odd = 0;
        int even = 0;
        for (var v : position) {
            if (v % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        return (even < odd ? even : odd);
    }
}
