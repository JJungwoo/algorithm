/*
[LeetCode] 567. Permutation in String
https://leetcode.com/problems/permutation-in-string/
*/
class Solution {
public:
    inline bool check_permutation(int *a, int *b) {
        for(int i=0;i<26;i++) {
            if(a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int check[26], stand[26];
        memset(check, 0, sizeof(check));
        memset(stand, 0, sizeof(stand));
        for(int i=0;i<s1.length();i++) {
            check[s1[i] - 'a']++;
        }
        for(int i=0;i<s2.length();i++) {
            stand[s2[i] - 'a']++;
            if(i >= s1.size()) {
                stand[s2[i - s1.length()] - 'a']--;
            }
            if(check_permutation(check, stand)) {
                return true;
            }
        }
        return false;
    }
};
