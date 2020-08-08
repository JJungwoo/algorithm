/*
[LeetCode] 1402. Reducing Dishes
https://leetcode.com/problems/reducing-dishes/
*/

class Solution {
public:
    vector<int> tmp;
    int maxSatisfaction(vector<int>& satisfaction) {
        int ans = 0;
        tmp = satisfaction;
        int idx = 0;
        while(idx <= tmp.size()){
            int tidx = 1;
            int tsum = 0;
            for(int i=idx;i<tmp.size();i++){
                tsum += tmp[i] * tidx;
                tidx++;
            }
            ans = max(tsum, ans);
            idx++;
        }
        return ans;
    }
};