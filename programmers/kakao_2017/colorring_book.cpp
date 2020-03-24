#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool visited[100][100];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
    
int bfs(int m, int n, int x, int y, vector<vector<int>> tmp, int num){
    int count = 1;
    queue<pair<int, int> > qp;
    visited[x][y] = true;
    qp.push(make_pair(x,y));
    tmp[x][y] = num;
    while(!qp.empty()){
        int x = qp.front().first, y = qp.front().second;
        qp.pop();
        for(int i=0;i<4;i++){
            int mx = x + dir[i][0], my = y + dir[i][1];
            if(mx < 0 || my < 0 || mx >= m || my >= n) continue;
            if(visited[mx][my]) continue;
            if(tmp[mx][my] != 1) continue;
            tmp[mx][my] = num;
            //cout<<tmp[mx][my]<<":"<<mx<<","<<my<<"\n";
            visited[mx][my] = true;
            count++;
            qp.push(make_pair(mx,my));
        }
    }
    return count;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    memset(visited, 0, sizeof(visited));
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] || picture[i][j] != 1) continue;
            int ret = bfs(m,n,i,j,picture,++number_of_area+1);  // 2, 3, 4 ... 
            if(ret > max_size_of_one_area){
                max_size_of_one_area = ret;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    //cout<<answer[0]<<","<<answer[1]<<"\n";
    return answer;
}