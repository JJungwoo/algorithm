/*
[LeetCode] 279. Perfect Squares
https://leetcode.com/problems/perfect-squares/
*/

class Solution {
    /*
    n을 만드는 제곱 수의 최소합 -> 메모이제이션으로 n값에 도달하는 최소 제곱수의 합
    */
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;
        for (int i=0;i<=n;i++) {
            for (int j=1;j*j<=n;j++) {
                if (i - (j * j) >= 0)
                    dp[i] = Math.min(dp[i], dp[i - (j * j)] + 1);
            }
        }
        return dp[n];
    }
}
