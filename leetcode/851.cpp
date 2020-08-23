/*
[LeetCode] 851. Loud and Rich
https://leetcode.com/problems/loud-and-rich/
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
    vector<int> g_quit;
    vector<int> path[501];
    bool visited[501];
    int tmin, minIdx;
    void dfs(int idx) {
        visited[idx] = true;
        if(tmin > g_quit[idx]) {
            tmin = g_quit[idx];
            minIdx = idx;
        }
        
        for(auto it : path[idx]) {
            if(visited[it]) continue;
            dfs(it);
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int maxIdx = 0;
        g_quit = quiet;
        for(int i=0;i<richer.size();i++) {
            path[richer[i][1]].push_back(richer[i][0]);
        }
        
        for(int i=0;i<quiet.size();i++) {
            tmin = quiet[i];
            minIdx = i;
            memset(visited, 0, sizeof(visited));
            dfs(i);
            ans.push_back(minIdx);
        }

        return ans;
    }
};

int main()
{
    io;
    int n;
    cin>>n;
    Solution solution = Solution();
    vector<int> result = solution.loudAndRich(n);

    return 0;
}
