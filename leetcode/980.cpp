/*
[LeetCode] 980. Unique Paths III
https://leetcode.com/problems/unique-paths-iii/
*/

class Solution {
public:
    struct pos{
        int x, y;  
    };
    
    int zeroCnt, xlen, ylen;
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> map;
    bool visited[21][21];
    pos start, end;
    
    int dfs(pos path, int cnt){
        int res = 0;
        int curX = path.x, curY = path.y;
        if(cnt == zeroCnt && map[curX][curY] == 2){
            return 1;
        }
        if(map[curX][curY] == 2) return 0;
            
        for(int i=0;i<4;i++){
            int mx = dir[i][0] + curX, my = dir[i][1] + curY;
            if(mx < 0 || my < 0 || mx >= xlen || my >= ylen) continue;
            if(visited[mx][my]) continue;
            if(map[mx][my] == -1) continue;
            visited[mx][my] = true;
            if(map[mx][my] == 0)
                res += dfs({mx, my}, cnt+1);
            else if(map[mx][my] == 2)
                res += dfs({mx, my}, cnt);
            visited[mx][my] = false;
        }
        
        return res;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int ans = 0;
        xlen = grid.size();
        ylen = grid[0].size();
        zeroCnt = 0;
        
        for(int i=0;i<xlen;i++){
            for(int j=0;j<ylen;j++){
                if(grid[i][j] == 1)
                    start.x = i, start.y = j;
                else if(grid[i][j] == 2) 
                    end.x = i, end.y = j;
                else if(grid[i][j] == 0)
                    zeroCnt++;
            }
        }
        map = grid;
        visited[start.x][start.y] = true;
        ans = dfs(start, 0);
        
        return ans;
    }
};