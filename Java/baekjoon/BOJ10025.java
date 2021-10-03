/*
[boj] 10025. 게으른 백곰
https://www.acmicpc.net/problem/10025
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int answer = 0;
        int N = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());
        // 0 : 얼음, 1 : 좌표
        int[][] arr = new int[N][2];
        for (int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine());
            arr[i][0] = Integer.parseInt(st.nextToken());
            arr[i][1] = Integer.parseInt(st.nextToken());
        }
        // 좌표순으로 오름차순 정렬
        Arrays.sort(arr, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });

        int lo = 1, hi = K * 2 + 1, sum = 0;
        int start = 0, end = 0;
        for (int i=0;i<arr.length;i++) {
            if (arr[i][1] > hi) break;
            sum += arr[i][0];
            end = i + 1;
        }
        while (end < arr.length) {
            answer = Math.max(answer, sum);
            hi++;
            if (hi >= arr[end][1]) {
                sum += arr[end][0];
                end++;
            }
            lo++;
            if (lo > arr[start][1]) {
                sum -= arr[start][0];
                start++;
            }
        }
        answer = Math.max(answer, sum);
        System.out.println(answer);
    }
}
