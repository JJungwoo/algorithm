/*
[boj] 5002. 도어맨
https://www.acmicpc.net/problem/5002
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
        int answer = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int X = Integer.parseInt(br.readLine());
        String str = br.readLine();
        int[] kind = new int[2];
        for (int i=0;i<str.length();i++) {
            if (str.charAt(i) == 'M') kind[0]++;
            else kind[1]++;

            if (Math.abs(kind[0] - kind[1]) > X) {
                if (i + 1 < str.length()) {
                    i++;
                    if (str.charAt(i) == 'M') kind[0]++;
                    else kind[1]++;
                    if (Math.abs(kind[0] - kind[1]) > X) {
                        answer = i - 1;
                        break;
                    }
                } else {
                    answer = i;
                    break;
                }
            }
        }
        System.out.println((answer == 0 ? str.length() : answer));
    }
}
