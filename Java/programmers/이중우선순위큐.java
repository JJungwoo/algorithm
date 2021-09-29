/*
[programmers] 이중우선순위큐
https://programmers.co.kr/learn/courses/30/lessons/42628
*/

import java.util.*;
class Solution {
    public int[] solution(String[] operations) {
        int[] answer = {0, 0};
        PriorityQueue<Integer> maxPQ = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> minPQ = new PriorityQueue<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        for (String str : operations) {
            String[] tokens = str.split(" ");
            if (tokens[0].equals("I")) {
                int v = Integer.parseInt(tokens[1]);
                map.put(v, (map.containsKey(v) ? map.get(v) + 1 : 1));
                maxPQ.add(v);
                minPQ.add(v);
            } else if (tokens[0].equals("D")) {
                if (tokens[1].equals("1")) {
                    while (!maxPQ.isEmpty()) {
                        int v = maxPQ.poll();
                        if (map.containsKey(v)) {
                            if (map.get(v) == 1) map.remove(v);
                            else map.put(v, map.get(v) - 1);
                            break;
                        }
                    }
                }
                if (tokens[1].equals("-1")) {
                    while (!minPQ.isEmpty()) {
                        int v = minPQ.poll();
                        if (map.containsKey(v)) {
                            if (map.get(v) == 1) map.remove(v);
                            else map.put(v, map.get(v) - 1);
                            break;
                        }
                    }
                }
            }
        }
        if (map.size() > 0) {
            while (!maxPQ.isEmpty()) {
                int v = maxPQ.poll();
                if (map.containsKey(v)) {
                    answer[0] = v;
                    break;
                }    
            }
            while (!minPQ.isEmpty()) {
                int v = minPQ.poll();
                if (map.containsKey(v)) {
                    answer[1] = v;
                    break;
                }
            }
        }
        
        return answer;
    }
}
