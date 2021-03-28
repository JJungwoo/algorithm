/*
[LeetCode] 198. House Robber
https://leetcode.com/problems/house-robber/
*/

class Solution {
public:

    int rob_house(int start, vector<int>& house) {
        int ret = 0;
        vector<int> dp(house.size(), 0);
        dp[0] = house[0];
        dp[1] = max(house[0], house[1]);
        dp[2] = max(house[0]+house[2], house[1]);
        for(int i=start;i<house.size();i++) {
            dp[i] = max(dp[i-2] + house[i], dp[i-1]);
        }
        return dp[house.size()-1];
    }

    int rob(vector<int>& nums) {

        if(nums.size() == 3)
            return max(nums[0] + nums[2], nums[1]);
        else if(nums.size() == 2)
            return max(nums[0], nums[1]);
        else if(nums.size() == 1)
            return nums[0];
        else if(nums.size() == 0)
            return 0;
        return max(rob_house(2, nums), rob_house(3, nums));
    }
};
