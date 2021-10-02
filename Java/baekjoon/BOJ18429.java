/*
[boj] 18429. 근손실
https://www.acmicpc.net/problem/18429
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int answer;
    static boolean[] visited;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        int[] arr = new int[N];
        st = new StringTokenizer(br.readLine());
        for (int i=0;i<N;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int[] temp = new int[N];
        visited = new boolean[N];
        backtracking(arr, temp, 0, K);
        System.out.println(answer);
    }
    public static void backtracking(int[] arr, int[] select, int idx, int K) {
        if (idx >= arr.length) {
            int sum = 500;
            for (int i=0;i<arr.length;i++) {
                sum += (select[i] - K);
                if (sum < 500) return;
            }
            answer++;
            return ;
        }

        for (int i=0;i<arr.length;i++) {
            if (visited[i]) continue;
            visited[i] = true;
            select[i] = arr[idx];
            backtracking(arr, select, idx + 1,  K);
            visited[i] = false;
        }
    }
}
