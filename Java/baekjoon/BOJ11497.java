/*
[boj] 11497. 통나무 건너뛰기
https://www.acmicpc.net/problem/11497
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int loop=0;loop<T;loop++) {
            int answer = 0;
            int N = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            List<Integer> list = new ArrayList<>();
            while (st.hasMoreTokens()) {
                list.add(Integer.parseInt(st.nextToken()));
            }
            Collections.sort(list);
            int t1 = list.get(0), t2 = list.get(0);
            int pos = 1;
            while (pos < list.size()) {
                answer = Math.max(answer, list.get(pos) - t1);
                t1 = list.get(pos);
                pos++;
                if (pos < list.size()) {
                    answer = Math.max(answer, list.get(pos) - t2);
                    t2 = list.get(pos);
                }
                pos++;
            }
            answer = Math.max(answer, Math.abs(t1 - t2));
            System.out.println(answer);
        }
    }
}
