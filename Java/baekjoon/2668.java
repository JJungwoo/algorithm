   
/*
[boj] 2668. 숫자고르기
https://www.acmicpc.net/problem/2668
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    private static List<Integer> answerList = new ArrayList<>();
    private static boolean[] visited;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[N + 1];
        visited = new boolean[N + 1];
        for (int i=1;i<=N;i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        for (int i=1;i<=N;i++) {
            if (visited[i]) continue;
            visited[i] = true;
            List<Integer> list = new ArrayList<>();
            list.add(i);
            numberSelectDfs(i, arr[i], list, arr);
        }
        System.out.println(answerList.size());
        answerList.stream().sorted().forEach(System.out::println);
    }

    public static void numberSelectDfs(int start, int cur, List<Integer> list, int[] arr) {

        if (start == cur) {
            answerList.addAll(list);
            return ;
        }
        if (visited[cur]) return ;

        visited[cur] = true;
        list.add(cur);
        numberSelectDfs(start, arr[cur], list, arr);
        list.remove(list.size() - 1);
        visited[cur] = false;
    }
}
