/*
[boj] 22233. 가희와 키워드
https://www.acmicpc.net/problem/22233
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class BOJ22233 {
//public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        HashSet<String> hs = new HashSet<>();
        for (int i = 0; i < N; i++) {
            hs.add(br.readLine());
        }
        for (int i = 0; i < M; i++) {
            input = br.readLine().split(",");
            for (String str : input) {
                if (hs.contains(str)) hs.remove(str);
            }
            System.out.println(hs.size());
        }
    }
}

