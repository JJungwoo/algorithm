
/*
[boj] 2961. 도영이가 만든 맛있는 음식
https://www.acmicpc.net/problem/2961
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Boj2961 {
    static long[] s;
    static long[] b;
    static int n;
    static long ans = Long.MAX_VALUE;
    static void dfs(int idx, long ts, long tb) {
        if (Math.log10(ts) > 17) return ;
        if (idx == n) {
            if (tb != 0)
                ans = Math.min(ans, Math.abs(ts - tb));
            return ;
        }

        dfs(idx+1, ts * s[idx], tb + b[idx]);
        dfs(idx+1, ts, tb);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        n = Integer.parseInt(br.readLine());
        s = new long[n];
        b = new long[n];
        for (int i=0;i<n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
           s[i] = Integer.parseInt(st.nextToken());
           b[i] = Integer.parseInt(st.nextToken());
        }
        dfs(0, 1, 0);
        System.out.println(ans);
    }
}
