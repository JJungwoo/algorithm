/*
[boj] 16508. 전공책
https://www.acmicpc.net/problem/16508
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[] ansCnt = new int[26];
    static int[] tmpCnt = new int[26];
    static int answer = 987654321;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String target = br.readLine();
        for (int i=0;i<target.length();i++) {
            ansCnt[target.charAt(i) - 'A']++;
        }
        int n = Integer.parseInt(br.readLine());
        BookInfo[] books = new BookInfo[n];
        for (int i=0;i<n;i++) {
            String[] tokens = br.readLine().split(" ");
            books[i] = new BookInfo(Integer.parseInt(tokens[0]), tokens[1]);
        }

        dfs(0, 0, books, n);
        System.out.println((answer == 987654321) ? - 1 : answer);
    }

    private static void dfs(int idx, int priceSum, BookInfo[] books, int n) {
        if (idx >= n) {
            for (int i=0;i<26;i++) {
                if (ansCnt[i] > tmpCnt[i])
                    return;
            }
            answer = Math.min(answer, priceSum);
            return;
        }

        for (int i=0;i<books[idx].title.length();i++) {
            tmpCnt[books[idx].title.charAt(i) - 'A']++;
        }
        dfs(idx + 1, priceSum + books[idx].price, books, n);
        for (int i=0;i<books[idx].title.length();i++) {
            tmpCnt[books[idx].title.charAt(i) - 'A']--;
        }
        dfs(idx + 1, priceSum, books, n);
    }

    static class BookInfo {
        int price;
        String title;

        public BookInfo(int price, String title) {
            this.price = price;
            this.title = title;
        }
    }
}
