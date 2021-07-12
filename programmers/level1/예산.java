/*
[programmers] 예산
https://programmers.co.kr/learn/courses/30/lessons/12982
*/
import java.util.*;

class Solution {
    public int solution(int[] d, int budget) {
        int answer = 0, sum = 0;
        Arrays.sort(d);
        for(int i=0;i<d.length;i++) {
            if (sum + d[i] <= budget) {
                sum += d[i];
                answer++;
            } else continue;
        }
        return answer;
    }
}
