/*
[programmers] 괄호 회전하기
https://programmers.co.kr/learn/courses/30/lessons/76502
*/
import java.util.*;
class Solution {
    public static int rollingStr(String str) {
        int ret = 0;
        for (int i=0;i<str.length();i++) {
            boolean check = true;
            Stack<Character> stack = new Stack<>();
            for (int j=0;j<str.length();j++) {
                int idx = (i + j) % str.length();
                Character item = str.charAt(idx);
                if (!stack.isEmpty() && stack.peek() == '[' && item == ']') {
                    stack.pop();
                } else if (!stack.isEmpty() && stack.peek() == '(' && item == ')') {
                    stack.pop();
                } else if (!stack.isEmpty() && stack.peek() == '{' && item == '}') {
                    stack.pop();
                } else if (item == '[' || item == '(' || item == '{') {
                    stack.push(str.charAt(idx));   
                } else {
                    check = false;
                    break;
                }
            }
            if (check) ret++;
        }
        return ret;
    }
    public int solution(String s) {
        int answer = -1;
        if (s.length() % 2 != 0) return 0;
        return answer = rollingStr(s);
    }
}
