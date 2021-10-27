/*
[programmers] 피로도
https://programmers.co.kr/learn/courses/30/lessons/87946
*/

class Solution {
    boolean[] visited;
    int ans;
    public int solution(int k, int[][] dungeons) {
        int answer = -1;
        visited = new boolean[dungeons.length];
        dfs(k, 0, dungeons);
        return answer = ans;
    }
    
    public void dfs(int life, int cnt, int[][] dungeons) {
        ans = Math.max(ans, cnt);
        
        for (int i=0;i<dungeons.length;i++) {
            if (visited[i] || life < dungeons[i][0]) continue;
            visited[i] = true;
            dfs(life - dungeons[i][1], cnt + 1, dungeons);
            visited[i] = false;
        }
    }
}
