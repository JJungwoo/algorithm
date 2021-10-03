/*
[boj] 1189. 컴백홈
https://www.acmicpc.net/problem/1189
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int answer;
    static boolean[][] visited;
    static int[][] dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[][] field = new int[R][C];
        visited = new boolean[R][C];
        for (int i=0;i<R;i++) {
            String input = br.readLine();
            for (int j=0;j<C;j++) {
                field[i][j] = (input.charAt(j) == '.' ? 0 : 1);
            }
        }
        visited[R-1][0] = true;
        dfs(R - 1, 0, 1, field, K, R, C);
        System.out.println(answer);
    }

    public static void dfs(int x, int y, int cnt, int[][] field, int K, int R, int C) {
        if (cnt > K) return ;
        if (x == 0 && y == C-1 && cnt == K) {
            answer++;
            return;
        }

        for (int i=0;i<4;i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
            if (visited[nx][ny]) continue;
            if (field[nx][ny] == 1) continue;
            visited[nx][ny] = true;
            dfs(nx, ny, cnt + 1, field, K, R, C);
            visited[nx][ny] = false;
        }
    }
}
