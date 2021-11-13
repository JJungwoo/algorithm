/*
[LeetCode] 441. Arranging Coins
https://leetcode.com/problems/min-stack/
*/

// 1. Simple Code
class Solution {
    public int arrangeCoins(int n) {
        int answer = 0;
        do {
            n -= ++answer;
        } while (n > 0);
        return (n == 0 ? answer : answer - 1);
    }
}

// 2. Binary Search 
class Solution {
  public int arrangeCoins(int n) {
    long left = 0, right = n;
    long k, curr;
    while (left <= right) {
      k = left + (right - left) / 2;
      curr = k * (k + 1) / 2;

      if (curr == n) return (int)k;

      if (n < curr) {
        right = k - 1;
      } else {
        left = k + 1;
      }
    }
    return (int)right;
  }
}

// 3. Math
class Solution {
  public int arrangeCoins(int n) {
    return (int)(Math.sqrt(2 * (long)n + 0.25) - 0.5);
  }
}
