/*
[boj] 1283. 단축키 지정
https://www.acmicpc.net/problem/1283
*/

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    private static final Set<Character> lowOpSet = new HashSet<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        String[] options = new String[N];
        for (int i = 0; i < N; i++) {
            options[i] = br.readLine();
            int pos = findChar(options[i], true);
            if (pos == -1) {
                pos = findChar(options[i], false);
            }
            System.out.println(appendAnsStr(options[i], pos));
        }
    }

    private static int findChar(String str, boolean first) {
        int pos = 0;
        do {
            char firstChar;
            if (first) {
                if (pos != 0) pos++;
                firstChar = str.toLowerCase().charAt(pos);
                if (firstChar != ' ' && !lowOpSet.contains(firstChar)) {
                    lowOpSet.add(firstChar);
                    return pos;
                }
            } else {
                for (int i = pos + 1; i < str.length(); i++) {
                    firstChar = str.toLowerCase().charAt(i);
                    if (firstChar != ' ' && !lowOpSet.contains(firstChar)) {
                        lowOpSet.add(firstChar);
                        return i;
                    }
                }
            }
        } while ((pos = str.indexOf(" ", pos + 1)) != -1);
        return -1;
    }

    private static String appendAnsStr(String src, int idx) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < src.length(); i++) {
            if (i == idx) {
                sb.append("[" + src.charAt(i) + "]");
            } else {
                sb.append(src.charAt(i));
            }
        }
        return sb.toString();
    }
}
