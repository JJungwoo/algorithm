/*
[LeetCode] 130. Surrounded Regions
https://leetcode.com/problems/surrounded-regions/
*/

class Solution {
public:
    int N, M;
    int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
    
    void dfs(int x, int y, vector<vector<char>>& board, vector<vector<bool>>& visited) {    
        vector<pair<int, int>> vlist;
        queue<pair<int, int>> qp;
        qp.push({x,y});
        vlist.push_back({x, y});
        visited[x][y] = true;
        bool check = true;
        while(!qp.empty()) {
            pair cur = qp.front(); qp.pop();
            if (cur.first == 0 || cur.first == N-1 ||
                cur.second == 0 || cur.second == M-1)
                check = false;
            for(int i=0;i<4;i++) {
                int nx = cur.first + dir[i][0], ny = cur.second + dir[i][1];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
                if(board[nx][ny] == 'X') continue;
                if(visited[nx][ny]) continue;
                visited[nx][ny] = true;
                vlist.push_back({nx, ny});
                qp.push({nx, ny});
            }
        }
        if(check) {
            for(auto it : vlist) {
                board[it.first][it.second] = 'X';
            }            
        }
    }
    void solve(vector<vector<char>>& board) {
        N = (int)board.size();
        if(!N) return;
        M = (int)board[0].size();
        vector<vector<bool>> visited(N, vector<bool>(M));
        
        vector<pair<int, int>> vp;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(!visited[i][j] && board[i][j] == 'O')
                    dfs(i, j, board, visited);   
            }
        }
     }
};