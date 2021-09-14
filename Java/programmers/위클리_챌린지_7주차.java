/*
[programmers] 위클리 챌린지 7주차 입실 퇴실
https://programmers.co.kr/learn/courses/30/lessons/86048
*/
import java.util.*;
class Solution {
    
    public int[] solution(int[] enter, int[] leave) {
        int[] answer = new int[enter.length];
        int etrcnt = 0, lvecnt = 0;
        HashMap<Integer, Integer> enterMap = new HashMap<>();
        while (lvecnt < leave.length) {
            if (enterMap.size() != 0) {
                int idx = leave[lvecnt] - 1;
                if (enterMap.containsKey(idx)) {
                    answer[idx] = enterMap.get(idx);
                    enterMap.remove(idx);
                    lvecnt++;
                    continue;
                }
            }
            enterMap.keySet().forEach(key -> enterMap.put(key, enterMap.get(key) + 1));
            enterMap.put(enter[etrcnt] - 1, enterMap.size());
            etrcnt++;
        }
        return answer;
    }
}
