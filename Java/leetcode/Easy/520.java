/*
[LeetCode] 520. Detect Capital
https://leetcode.com/problems/detect-capital/
*/

class Solution {
    public boolean detectCapitalUse(String word) {
        if (word == null || word.isBlank()) {
            return false;
        }
        int checkCapital = 0;
        for (int i = 0; i < word.length(); i++) {
            if (Character.isUpperCase(word.charAt(i))) {
                checkCapital++;
            }
        }
        return (word.length() == checkCapital || checkCapital == 0 || 
                (checkCapital == 1 && Character.isUpperCase(word.charAt(0))));
    }
}
