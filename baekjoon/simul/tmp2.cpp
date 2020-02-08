#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
char a[12][6]; // input 배열
int visited[12][6]; // 방문했는지 아닌지 확인
bool whenbumb[1000]; // 1000 번이상 터지지는 않겠지.
int maxcnt = 0;
// 방향  설정 
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};
// 중력
void bfs(int x, int y, int cnt){
    queue <pair<int,int> > q; 
    queue <pair<int,int> > saveXY;
    // x,y 좌표를 저장할 bfs
    visited[x][y] = cnt;
    q.push(make_pair(x,y)); // 큐에 입력
    saveXY.push(make_pair(x,y));
    cout << cnt;
    while(!q.empty()){
        // 큐가 비어 있지 않을 때 까지
        // 현재 위치 셋팅 (now x, now y)
        // 처음에 R 이 다 끝나면 나간다.
        int nx = q.front().first;
        int ny = q.front().second;
        q.pop(); // 나가줌
        for(int i = 0; i < 4 ; i++ ){
// 갈 방향(go x, go y) 를 현재 위치에 방향을 더해 만든다.
            int gx = nx + dx[i];
            int gy = ny + dy[i];
// 갈 뱡향 좌표를 들려보지 않았고 
            if(visited[gx][gy] == 0 && a[x][y] == a[gx][gy] ){
                q.push(make_pair(gx,gy)); // 입력
                visited[gx][gy] = cnt; 
                saveXY.push(make_pair(gx,gy)); // 저장 큐에 일단 지나온 애들 다 집어넣어주기
            }
        }
    }
// 터질수 있는지 확인하고 터질 수 있으면 whenbomb 에 값을 넣는다.
    if(saveXY.size() >=4) {
        whenbumb[cnt] = 1;
        maxcnt = max(cnt,maxcnt);
        while(!saveXY.empty()){
            // 터지는 좌표 (bomb x, bomb y)
            int bx = saveXY.front().first;
            int by = saveXY.front().second;
            a[bx][by] ='.';
            saveXY.pop();
        }
        // 중력 구현
        queue <char> gravity; // 문자를 저장함
        for(int gj = 0 ; gj < 6 ; gj++){
            // 중력 열
            // 이거는 열검사를 해야되기 때문에 
            for(int gi = 11; gi >= 0 ; gi++){
                // 중력 행
                // 아래부터 . 가 아닌 값을 q 에 담는다.
                if(a[gi][gj] != '.'){
                    gravity.push(a[gi][gj]);
                    a[gi][gj] = '.';
                }
            }
            int gpoint = 11;
            while(!gravity.empty()){
                a[gpoint][gj] = gravity.front();
                gravity.pop();
            }
        }
    }else{
        while(!saveXY.empty()){
            // saveXY 비워주기
            saveXY.pop();
        }
    }
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cout<< a[i][j];
        }
        cout <<"\n";
    }    
}
int main(){
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            cin >> a[i][j];
        }
    }     
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 6; j++){
            if(a[i][j] != '.' && visited[i][j] == 0)
            // 빈 공간이 아니고 방문안했을 때.
                bfs(i,j,0);
        }  
    }
    cout << maxcnt <<"\n";
}