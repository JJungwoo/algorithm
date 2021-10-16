/*
[programmers] 행렬 테두리 회전하기
https://programmers.co.kr/learn/courses/30/lessons/77485
*/

class Solution {
    int[][] dir = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };
    int[][] arr;
    public int[] solution(int rows, int columns, int[][] queries) {
        int[] answer = new int[queries.length];
        arr = new int[rows + 1][columns + 1];
        int value = 0;
        for (int i=1;i<=rows;i++) {
            for (int j=1;j<=columns;j++) {
                arr[i][j] = ++value; 
            }
        }
        for (int i=0;i<queries.length;i++) {
            answer[i] = rotateArr(queries[i][0], queries[i][1], queries[i][2], queries[i][3]);
        }
        return answer;
    }
    private int rotateArr(int x1, int y1, int x2, int y2) {
        int tmpValue = arr[x1][y1];
        int ret = tmpValue;
        int x = x1, y = y1;
        for (int i=0;i<4;i++) {
            while (true) {
                int nx = x + dir[i][0], ny = y + dir[i][1];
                if (nx < x1 || ny < y1 || nx > x2 || ny > y2) {
                    break;
                }
                ret = Math.min(ret, arr[nx][ny]);
                arr[x][y] = arr[nx][ny];
                x = nx;
                y = ny;
            }
        }
        arr[x1][y1 + 1] = tmpValue;
        return ret;
    }
}
