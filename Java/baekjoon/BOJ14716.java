/*
[boj] 14716. 현수막
https://www.acmicpc.net/problem/14716
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class BOJ14716 {
    static int[][] dir = { {-1, -1}, {-1, 0}, {-1, 1},
                            {0, -1}, {0, 1},
                            {1, -1}, {1, 0}, {1, 1} };
    static boolean[][] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int M = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int[][] board = new int[M][N];
        for (int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine());
            for (int j=0;j<N;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int answer = 0;
        visited = new boolean[M][N];
        for (int i=0;i<M;i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j] && board[i][j] == 1) {
                    answer++;
                    bfs(i, j, board, M, N);
                }
            }
        }
        System.out.println(answer);
    }

    public static void bfs (int x, int y, int[][] board, int m, int n) {
        Queue<Pos> q = new LinkedList<>();
        q.offer(new Pos(x, y));
        visited[x][y] = true;
        while (!q.isEmpty()) {
            Pos cur = q.peek(); q.poll();
            for (int i=0;i<8;i++) {
                int nx = cur.x + dir[i][0];
                int ny = cur.y + dir[i][1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                if (visited[nx][ny]) continue;
                if (board[nx][ny] == 0) continue;
                visited[nx][ny] = true;
                q.offer(new Pos(nx, ny));
            }
        }
    }
}

class Pos {
    int x;
    int y;

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }
}
