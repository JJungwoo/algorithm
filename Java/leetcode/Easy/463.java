/*
[LeetCode] 463. Island Perimeter
https://leetcode.com/problems/island-perimeter/
*/

class Solution {
    private int[][] dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    public int islandPerimeter(int[][] grid) {
        int answer = 0;
        for (int i=0;i<grid.length;i++) {
            for (int j=0;j<grid[i].length;j++) {
                if (grid[i][j] == 1) {
                    answer += checkLandRound(i, j, grid.length, grid[i].length, grid);
                }
            }
        }
        return answer;
    }
    
    private int checkLandRound(int x, int y, int N, int M, int[][] grid) {
        int ret = 0;
        for (int i=0;i<4;i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) {
                ret++;
            } else if (grid[nx][ny] == 0) {
                ret++;
            }
        }
        return ret;
    }
}
