/*
[boj] 24392. 영재의 징검다리
https://www.acmicpc.net/problem/24392
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    // 왼쪽 위, 위, 오른쪽 위
    private final static int[][] way = {{-1, -1}, {-1, 0}, {-1, 1}};
    private final static int MOD = 1_000_000_007;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tokens = br.readLine().split(" ");
        int N = Integer.parseInt(tokens[0]);
        int M = Integer.parseInt(tokens[1]);

        int[][] glass = new int[N][M + 2];
        long[][] dp = new long[N][M + 2];
        for (int i = 0; i < N; i++) {
            tokens = br.readLine().split(" ");
            for (int j = 0; j < M; j++) {
                glass[i][j + 1] = Integer.parseInt(tokens[j]);
            }
        }

        for (int j = 1; j <= M; j++) {
            dp[N - 1][j] = 1;
        }

        for (int i = N - 1; i > 0; i--) {
            for (int j = 1; j <= M; j++) {
                for (int[] ints : way) {
                    int x = i + ints[0];
                    int y = j + ints[1];
                    if (glass[i][j] == 1 && glass[x][y] == 1) {
                        dp[x][y] += (dp[i][j] % MOD);
                    }
                }
            }
        }

        long ans = 0;
        for (int j = 1; j <= M; j++) {
            ans += dp[0][j];
        }
        System.out.println(ans % MOD);
    }
}
