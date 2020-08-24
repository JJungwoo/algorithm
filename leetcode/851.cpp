/*
[LeetCode] 851. Loud and Rich
https://leetcode.com/problems/loud-and-rich/

Input: 
richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]]
quiet = [3,2,5,4,6,1,7,0]

Output: 
[5,5,2,5,4,5,6,7]
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

class Solution {
public:
    vector<int> ans;
    vector<int> path[501];
    int dfs(int idx, vector<int>& quiet) {
        if(ans[idx] >= 0) return ans[idx];
        ans[idx] = idx;
        for(auto it : path[idx]) {
            if(quiet[ans[idx]] > quiet[dfs(it, quiet)])
                ans[idx] = ans[it];
        }
        return ans[idx];
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        for(int i=0;i<richer.size();i++) {
            path[richer[i][1]].push_back(richer[i][0]);
        }
        ans.resize(quiet.size(), -1);
        for(int i=0;i<quiet.size();i++) {
            ans[i] = dfs(i, quiet);
        }

        return ans;
    }
};

int main()
{
    io;
    //Solution solution = Solution();
    //vector<int> result = solution.loudAndRich();

    return 0;
}
