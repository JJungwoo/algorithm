/*
[programmers] 2017 카카오 코드 예선 카카오프렌즈 컬러링북
https://programmers.co.kr/learn/courses/30/lessons/1829
*/
#include <bits/stdc++.h>

using namespace std;
const int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
struct obj {
    int x, y;
};
int bfs(int x, int y, int color, vector<vector<int>> &picture, int m, int n) {
    int ret = 1;
    queue<obj> q;
    picture[x][y] = -1;
    q.push({x, y});
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        for(int i=0;i<4;i++) {
            int nx = cur.x + dir[i][0], ny = cur.y + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (picture[nx][ny] != color) continue;
            picture[nx][ny] = -1;
            q.push({nx, ny});
            ret++;
        }
    }
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for(int i=0;i<picture.size();i++) {
        for(int j=0;j<picture[i].size();j++) {
            if (picture[i][j] > 0) {
                max_size_of_one_area = max(max_size_of_one_area, bfs(i, j, picture[i][j], picture, m, n));
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
