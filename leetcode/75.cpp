/*
[LeetCode] 75. Sort Colors
https://leetcode.com/problems/sort-colors/
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m;
        for(auto n : nums) {
            m[n]++;
        }
        nums.clear();
        for(auto it : m) {
            for(int i=0;i<it.second;i++) {
                nums.push_back(it.first);
            }
        }
    }
};