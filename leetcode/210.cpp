/*
[LeetCode] 210. Course Schedule II
https://leetcode.com/problems/course-schedule-ii/
*/

class Solution {
public:
    bool chk;
    int cnt[2001], vis[2001];
    vector<int> seq[2001], ans;
    void dfs(int idx) {
        if(cnt[idx] < 0) {
            chk = true;
            return;
        }
        
        for(auto nxt : seq[idx]) {
            cnt[idx]--;
            if(!vis[nxt]) {
                dfs(nxt);
            }
        }
        
        if(!vis[idx]) {
            ans.push_back(idx);
            vis[idx] = true;
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<prerequisites.size();i++) {
            seq[prerequisites[i][0]].push_back(prerequisites[i][1]);
            cnt[prerequisites[i][0]]++;
        }
        
        for(int i=0;i<numCourses;i++) {
            if(!vis[i]) {
                dfs(i);
            }
        }
        if(chk) ans.clear();
        return ans;
    }
};