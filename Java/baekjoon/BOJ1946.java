/*
[boj] 1946. 신입 사원
https://www.acmicpc.net/problem/1946
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        while (T-- != 0){
            int N = Integer.parseInt(br.readLine());
            Grade[] grades = new Grade[N];
            for (int i = 0; i < N; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                grades[i] = new Grade(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
            }

            Arrays.sort(grades);

            int minValue = 100001;
            int answer = 0;
            for (var v : grades) {
                if (v.score2 < minValue) {
                    minValue = v.score2;
                    answer++;
                }
            }

            System.out.println(answer);
        }
    }
}

class Grade implements Comparable<Grade> {
    int score1;
    int score2;

    public Grade(int score1, int score2) {
        this.score1 = score1;
        this.score2 = score2;
    }

    @Override
    public int compareTo(Grade o) {
        return Integer.compare(this.score1, o.score1);
    }
}
