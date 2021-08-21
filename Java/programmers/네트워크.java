/*
[programmers] 네트워크
https://programmers.co.kr/learn/courses/30/lessons/43162
*/

class Solution {
    static boolean[] visited;
    public static void dfs(int idx, int[][] computers, int N) {
        if (idx >= N) return;
        visited[idx] = true;
        for(int i=0;i<N;i++) {
            if (visited[i]) continue;
            if (computers[idx][i] == 1) {
                dfs(i, computers, N);
            }
        }
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        visited = new boolean[n];
        for(int i=0;i<n;i++) {
            if (visited[i]) continue;
            answer++;
            dfs(i, computers, n);
        }
        return answer;
    }
}
