/*
[boj] 14658. 하늘에서 별똥별이 빗발친다
https://www.acmicpc.net/problem/14658
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ14658 {
//public class Main {
    public static void main(String[] args) throws IOException {
        int N, M, L, K, answer = 0;

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        N = Integer.parseInt(input[0]);
        M = Integer.parseInt(input[1]);
        L = Integer.parseInt(input[2]);
        K = Integer.parseInt(input[3]);

        int[][] star = new int[K][2];
        for(int i = 0; i < K; i++) {
            input = br.readLine().split(" ");
            star[i][0] = Integer.parseInt(input[0]);
            star[i][1] = Integer.parseInt(input[1]);
        }

        for(int i = 0; i < K; i++) {
            for(int j = 0; j < K; j++) {
                int x = star[i][0];
                int y = star[j][1];
                int cnt = 0;
                for(int z = 0; z < K; z++) {

                    int nx = star[z][0];
                    int ny = star[z][1];
                    if (x <= nx && nx <= x + L &&
                        y <= ny && ny <= y + L) {
                        cnt++;
                    }
                    answer = Math.max(answer, cnt);
                }
            }
        }
        System.out.println(K - answer);
    }
}

