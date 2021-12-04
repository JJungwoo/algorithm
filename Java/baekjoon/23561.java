
   
/*
[boj] 23561. Young한 에너지는 부족하다
https://www.acmicpc.net/problem/23561
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N * 3];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N * 3; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);
				// N개의 그룹중 가운데 그룹을 나눠 또 그 사이에서 최대 최소 차이를 구한다.
        System.out.println(arr[2 * N - 1] - arr[N]);
    }
}
