/*
[programmers] [1차] 프렌즈4블록
https://programmers.co.kr/learn/courses/30/lessons/17679
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

inline bool find_bang(int x, int y, vector<string> &board) {
    if(board[x][y] == board[x+1][y] && board[x+1][y] == board[x][y+1] 
      && board[x][y+1] == board[x+1][y+1] && board[x+1][y+1] == board[x][y]) 
        return true;
    return false;
}

bool solve(int m, int n, vector<string> &board) {
    vector<pair<int, int> > vp;
    for(int i=0;i<m-1;i++) {
        for(int j=0;j<n-1;j++) {
            if(board[i][j] != ' ' && find_bang(i, j, board)) {
                vp.push_back({i, j});
            }
        }
    }
    
    if(!vp.empty()) {
        for(auto it : vp) {
            int x = it.first, y = it.second;
            board[x][y] = board[x+1][y] = board[x][y+1] = board[x+1][y+1] = ' ';
        }
        return true;
    }
    
    return false;
}

void gravity(int m, int n, vector<string> &board) {
    for(int i=n-1;i>=0;i--) {
        for(int j=m-2;j>=0;j--) {
            if(board[j][i] != ' ') {
                int x = j, y = i;
                while(x+1 < m) {
                    if(board[x+1][y] == ' ') {
                        auto tmp = board[x][y];
                        board[x][y] = board[x+1][y];
                        board[x+1][y] = tmp;
                        x++;
                    }
                    else 
                        break;
                }
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while(solve(m, n, board)){
        gravity(m, n, board);
    }
        
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(board[i][j] == ' ') answer++;
        }
    }
    return answer;
}