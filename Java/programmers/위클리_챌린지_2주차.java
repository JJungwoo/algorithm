/*
[programmers] 위클리 챌린지 2주차
https://programmers.co.kr/learn/courses/30/lessons/83201
*/
class Solution {
    public static String choseGrade (int value) {
        return switch (value/10) {
            case 9 -> "A";
            case 8 -> "B";
            case 7 -> "C";
            case 6, 5 -> "D";
            default -> "F";
        };
    }
    public static String calGradeInfo(int[][] scores, int N) {
        StringBuilder answer = new StringBuilder();
        for(int i=0;i<N;i++) {
            int sum = 0, maxScore = 0, minScore = 100, myScore = 0, delCnt = 0;
            for(int j=0;j<N;j++) {
                if (i == j) {
                    myScore = scores[j][i];
                } else {
                    maxScore = maxScore > scores[j][i] ? maxScore : scores[j][i];
                    minScore = minScore < scores[j][i] ? minScore : scores[j][i];
                }
                sum += scores[j][i];
            }
            if (myScore > maxScore || myScore < minScore) {
                sum -= myScore;
                delCnt++;
            }
            answer.append(choseGrade(sum/(N-delCnt)));
        }
        return answer.toString();
    }
    public String solution(int[][] scores) {
        String answer = "";
        return answer = calGradeInfo(scores, scores.length);
    }
}
