/*
[boj] 21758. 꿀 따기
https://www.acmicpc.net/problem/21758
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ21758 {
    public static void main(String[] args) throws Exception {
        int answer = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N + 1];
        int[] psum = new int[N + 1];
        for (int i=1;i<=N;i++) {
            arr[i] = Integer.parseInt(st.nextToken());
            psum[i] = arr[i] + psum[i-1];
        }

        // 꿀통이 오른쪽 끝, 꿀벌1이 왼쪽 끝, 꿀벌2가 랜덤 위치
        int sum = psum[N] - psum[1];
        for (int i=2;i<N;i++) {
            // sum : 꿀벌1이 모은 꿀
            // psum[i] - psum[i - 1] : 꿀벌2가 시작한 위치
            // psum[N] - psum[i] : 꿀벌2가 꿀을 모은 전체 양 (자신의 위치 빼고)
            answer = Math.max(answer, sum - (psum[i] - psum[i-1]) + (psum[N] - psum[i]));
        }

        // 꿀통이 왼쪽 끝, 꿀벌1이 오른쪽 끝, 꿀벌2가 랜덤 위치
        sum = psum[N-1];
        for (int i=2;i<N;i++) {
            // sum : 꿀벌1이 모은 꿀
            // psum[i] - psum[i-1] : 꿀벌2가 시작한 위치
            // psum[i - 1] : 꿀벌2가 꿀을 모은 전체 양 (자신의 위치 빼고)
            answer = Math.max(answer, sum - (psum[i] - psum[i-1]) + psum[i - 1]);
        }

        // 꿀통이 랜덤 위치, 꿀벌1이 오른쪽 끝, 꿀벌2가 왼쪽 끝 위치
        for (int i=2;i<N;i++) { // i가 꿀통의 위치
            // psum[i] - psum[1] : 꿀벌1이 꿀통 전까지 모은 꿀의 양 (자신의 위치 빼고)
            // psum[N - 1] - psum[i - 1] : 꿀벌2가 꿀통 전까지 모은 꿀의 양 (자신의 위치 빼고)
            answer = Math.max(answer,  (psum[i] - psum[1]) + (psum[N - 1] - psum[i - 1]));
        }

        System.out.println(answer);
    }
}
