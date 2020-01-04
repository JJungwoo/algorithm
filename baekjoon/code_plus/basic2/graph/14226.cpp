/*
[BOJ] 14226. 이모티콘
문제가 이해가 안되서 어려웠다. 문제는 간단하게 처음 1개의 이모티콘이 있으면 해당 이모티콘을
복사 붙여넣기 총 2번의 연산으로 2개를 만들 수 있다. 붙여넣기는 클립 보드에 복사하면 계속 할 수 있다.
따라서 6번의 경우 복사 붙여넣기 붙여넣기 하면 이모티콘이 3개가 되고 연산은 3이 된다. 그리고 3개를 모두
복사하고 붙여넣기하면 총 5번의 연산으로 6개의 이모티콘을 출력할 수 있다.
2차원 배열[화면에 있는 이모티콘][클립보드에 있는 이모티콘열]
ref: 
dfs 방식: https://rebas.kr/749
dp 방식: http://wookje.dance/2018/06/24/boj-14226-boj-%EC%9D%B4%EB%AA%A8%ED%8B%B0%EC%BD%98/
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int s;
queue<pair<int, int> > q;
int map[2001][2001];
void bfs(){
    q.push(make_pair(1, 0));
    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        if(x == s){
            cout<<map[x][y]<<"\n";
            return;
        }
        int mx[] = {x, x+y, x-1}, my[] = {x, y, y}; // 복사 붙여넣기 삭제
        for(int i=0;i<3;i++){
            if(mx[i]<0||mx[i]>2*s)continue;
            if(map[mx[i]][my[i]])continue;
            q.push(make_pair(mx[i], my[i]));
            map[mx[i]][my[i]] = map[x][y] + 1;
        }
    }
}

int main()
{
    io;
    cin>>s;
    bfs();
    return 0;
}