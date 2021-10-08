/*
[programmers] 전력망을 둘로 나누기
https://programmers.co.kr/learn/courses/30/lessons/86971
*/

import java.util.*;
class Solution {
    public int solution(int n, int[][] wires) {
        int answer = 100;
        List<Integer>[] list = new ArrayList[n + 1];
        boolean[] visited = new boolean[n + 1];
        for (int i=1;i<=n;i++) {
            list[i] = new ArrayList<Integer>();
        }
        for (int i=0;i<wires.length;i++) {
            list[wires[i][0]].add(wires[i][1]);
            list[wires[i][1]].add(wires[i][0]);
        }
        for (int i=1;i<=n;i++) {
            for (int j=0;j<list[i].size();j++) {
                visited[list[i].get(j)] = true;
                answer = Math.min(answer, bfs(i, list, visited, n));
                Arrays.fill(visited, false);
            }
        }
        return answer;
    }
    private int bfs(int start, List<Integer>[] list, boolean[] visited, int n) {
        int ret = 0;
        Queue<Integer> q = new LinkedList<>();
        visited[start] = true;
        q.offer(start);
        while (!q.isEmpty()) {
            int cur = q.poll();
            ret++;
            for (int next : list[cur]) {
                if (visited[next]) continue;
                visited[next] = true;
                q.offer(next);
            }
        }
        return Math.abs((n - ret) - ret);
    }
}
