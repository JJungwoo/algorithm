/*
[LeetCode] 881. Boats to Save People
https://leetcode.com/problems/boats-to-save-people/
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int left = 0, right = people.size() - 1;
        int ans = 0;
        while(left < right) {
            if(people[left] + people[right] <= limit) {
                ans++;
                left++;
                right--;
            } else {
                right--;
            }
        }
        return people.size() - ans;
    }
};
