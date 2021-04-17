/*
[LeetCode] 560. Subarray Sum Equals K
https://leetcode.com/problems/subarray-sum-equals-k/
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int answer = 0;
        int N = nums.size();
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = 1;
        for(int i=0;i<N;i++) {
            sum += nums[i];
            if (m.find(sum - k) != m.end()) {
                answer += m[sum - k];
            }
            m[sum] = m[sum] + 1;
        }
        return answer;
    }
};
