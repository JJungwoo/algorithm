/*
[LeetCode] 11. Container With Most Water
https://leetcode.com/problems/https://leetcode.com/problems/container-with-most-water/
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = height.size()-1, ans = 0;
        while(lo <= hi) {
            int h = min(height[lo], height[hi]);
            int w = hi - lo;
            
            ans = max(ans, h * w);
            if (height[lo] > height[hi]) {
                hi--;
            } else {
                lo++;
            }
        }
        return ans;
    }
};