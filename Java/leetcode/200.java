/*
[LeetCode] 200. Number of Islands
https://leetcode.com/problems/number-of-islands/
*/
class Solution {
    int[][] dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
    boolean[][] visited;
    public int numIslands(char[][] grid) {
        int ans = 0;
        visited = new boolean[grid.length][grid[0].length];
        for (int i=0;i<grid.length;i++) {
            for (int j=0;j<grid[i].length;j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    ans++;
                    bfs(i, j, grid, grid.length, grid[0].length);
                }
            }
        }
        return ans;
    }
    
    private void bfs(int x, int y, char[][] grid, int n, int m) {
        Queue<Pos> q = new LinkedList<>();
        q.add(new Pos(x, y));
        visited[x][y] = true;
        while (!q.isEmpty()) {
            Pos cur = q.peek(); q.poll();
            for (int i=0;i<4;i++) {
                int nx = cur.x + dir[i][0];
                int ny = cur.y + dir[i][1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (visited[nx][ny]) continue;
                if (grid[nx][ny] == '0') continue;
                visited[nx][ny] = true;
                q.offer(new Pos(nx, ny));
            }
        }
    }
    
    class Pos {
        int x;
        int y;
        public Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
