/*
[boj] 13335. 트럭
https://www.acmicpc.net/problem/13335
*/

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] tokens = br.readLine().split(" ");
        int n = Integer.parseInt(tokens[0]);
        int w = Integer.parseInt(tokens[1]);
        int l = Integer.parseInt(tokens[2]);
        int[] truck = new int[n];

        tokens = br.readLine().split(" ");

        for (int i = 0; i < n; i++) {
            truck[i] = Integer.parseInt(tokens[i]);
        }

        SolutionQueue sQueue = new SolutionQueue(w, l);
        int answer = 0;
        int idx = 0;
        while (sQueue.simulOneTimeLoop() > 0 || idx < n) {
            if (idx < n && sQueue.inQueue(truck[idx])) {
                idx++;
            }
            answer++;
        }

        System.out.println(answer);
    }
}

class SolutionQueue {
    private int length;
    private int totalWeight;
    private int curWeight;
    // 무게, 위치
    Queue<int[]> load = new LinkedList<>();

    public SolutionQueue(int length, int totalWeight) {
        this.length = length;
        this.totalWeight = totalWeight;
    }

    // 현재 큐에 트럭이 들어올 수 있는지 확인 후 추가
    public boolean inQueue(int weight) {
        if (weight + curWeight <= totalWeight) {
            curWeight += weight;
            load.add(new int[]{weight, 0});
            return true;
        }
        return false;
    }

    // 한번 호출마다 1초
    public int simulOneTimeLoop() {
        int curSize = load.size();
        if (curSize == 0) {
            return 0;
        }
        int cnt = 0;
        while (!load.isEmpty()) {
            if (cnt >= curSize) {
                break;
            }
            var tmp = load.poll();
            tmp[1]++;
            if (tmp[1] < length) {
                load.add(tmp);
            } else {
                curWeight -= tmp[0];
            }
            cnt++;
        }
        return 1;
    }
}
