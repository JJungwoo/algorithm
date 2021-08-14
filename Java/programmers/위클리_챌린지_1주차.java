/*
[programmers] 위클리 챌린지 1주차
https://programmers.co.kr/learn/courses/30/lessons/82612
*/
class Solution {
    public long solution(int price, int money, int count) {
        long answer = 0;
        for (int i=1;i<=count;i++) {
            answer += price * i;
        }
        return (answer - money < 0 ? 0 : answer - money);
    }
}
