/*
[programmers] 위클리 챌린지 7주차 입실 퇴실
https://programmers.co.kr/learn/courses/30/lessons/86048
*/

class Solution {
    public int solution(int[][] sizes) {
        int max = 0;
        int min = 0;
        for (int[] size : sizes) {
            max = Math.max(max, Math.max(size[0], size[1]));
            min = Math.max(min, Math.min(size[0], size[1]));
        }
        return max * min;
    }
}
