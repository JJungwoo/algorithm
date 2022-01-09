/*
[LeetCode] 1094. Car Pooling
https://leetcode.com/problems/car-pooling/
*/
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        Arrays.sort(trips, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        int endPoint = trips[trips.length - 1][2];
        int idx = 0, startPoint = 0;
        int curWeight = 0;
        // 사람수, 도착 위치 => 도착위치 작은 순으로 정렬
        PriorityQueue<int[]> tripToSortedPQ = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[1] - o2[1];
            }
        });
        for (int i = 1; i <= endPoint; i++) {
            while (!tripToSortedPQ.isEmpty()) {
                if (tripToSortedPQ.peek()[1] > i) {
                    break;
                }
                curWeight -= tripToSortedPQ.poll()[0];
            }
            while (idx < trips.length && trips[idx][1] <= i) {
                tripToSortedPQ.add(new int[]{trips[idx][0], trips[idx][2]});
                curWeight += trips[idx][0];
                idx++;
            }
            if (curWeight > capacity) {
                return false;
            }
        }
        return true;
    }
}
