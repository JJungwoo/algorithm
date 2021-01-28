/*
[LeetCode] 12. Integer to Roman
https://leetcode.com/problems/integer-to-roman/
*/

#define MAX_ELEM 7 + 6
class Solution {
public:
    int values[MAX_ELEM] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols = "MDCLXVI";
    inline void repeat_symbol(int loop, char c, string &target) {
        while (loop--)
            target += c;
    }
    string intToRoman(int num) {
        string ans = "";
        int idx = 0;
        for (int i=0;i<MAX_ELEM;i++) {
            int tmp = num / values[i];
            if ((i+1) % 2 != 0 && tmp > 0) {
                repeat_symbol(tmp, symbols[i/2], ans);
                num %= values[i];
            } else if (tmp > 0) {
                (values[i] % 9 == 0) ? ans += symbols[i/2+2] : ans += symbols[i/2+1];
                ans += symbols[i/2];
                num %= values[i];
            }
        }
        return ans;
    }
};