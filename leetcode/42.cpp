/*
[LeetCode] 42. Trapping Rain Water
https://leetcode.com/problems/trapping-rain-water/
*/
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 0) return 0;
        stack<int> s;
        int stand = 0, ans = 0;
        for (int i=0;i<height.size();i++) {
            while (!s.empty() && stand <= height[i] && height[s.top()] <= height[i]) {
                ans += stand - height[s.top()];
                s.pop();
                if (s.empty()) stand = 0;
            }
            s.push(i);
            stand = max(stand, height[i]);
        }
        stand = height[s.top()];
        s.pop();
        while(!s.empty()) {
            if (height[s.top()] < stand) {
                ans += stand - height[s.top()];
            }
            stand = max(stand, height[s.top()]);
            s.pop();
        }
        return ans;
    }
};
