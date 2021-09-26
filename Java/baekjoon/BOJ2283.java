/*
[boj] 2283. 구간 자르기
https://www.acmicpc.net/problem/2283
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ2283 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        long K = Long.parseLong(st.nextToken());
        long[] arr = new long[1_000_001];
        int maxLen = 0;
        for (int i=0;i<N;i++) {
            int A, B;
            st = new StringTokenizer(br.readLine());
            A = Integer.parseInt(st.nextToken());
            B = Integer.parseInt(st.nextToken());
            maxLen = Math.max(maxLen, B);
            for (int j=A;j<B;j++) {
                arr[j]++;
            }
        }
        boolean find = false;
        int lo = 0, hi = 0;
        long sum = 0;
        while (true) {
            if (sum == K) {
                find = true;
                break;
            }
            if (sum < K) {
                if (maxLen < hi) break;
                sum += arr[hi];
                hi++;
            } else {
                sum -= arr[lo];
                lo++;
            }
        }
        if (!find) {
            lo = hi = 0;
        }
        System.out.println(lo + " " + hi);
    }
}
