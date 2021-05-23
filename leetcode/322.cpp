/*
[LeetCode] 322. Coin Change
https://leetcode.com/problems/coin-change/
*/
#define MAX_INT 1e9
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1);
        dp[0] = 0;

        for(int i=1;i<=amount;i++) {
            dp[i] = MAX_INT;
        }

        for(int j=0;j<coins.size();j++) {
            for(int i=1;i<=amount;i++) {
                if (i - coins[j] >= 0) {
                    dp[i] = min(dp[i], dp[i-coins[j]] + 1);
                }
            }
        }
        return dp[amount] == MAX_INT ? -1 : dp[amount];
    }
};
