/*
[boj] 19237. 어른 상어 
https://www.acmicpc.net/problem/19237
*/
/*
상어는 K번 이동하고 사라짐
자신의 냄세가 없는 칸으로 먼저 이동 -> 없으면
자신의 냄새가 있는 칸으로 이동 -> 가능한 칸이 여러개면 우선순위 적용

같은 상어라도 현재 상어가 보고 있는 방향에 따라 또 다를 수 있다. 
상어가 맨 처음에 보고 있는 방향은 입력으로 주어지고, 
그 후에는 방금 이동한 방향이 보고 있는 방향이 된다.

이동 후 한 칸에 여러 마리의 상어가 있으면 가장 작은 번호 상어를 제외 모두 사라짐

만약 벽에 붙이치면?? 현재 방향의 우선순위 방향으로 이동?
그런데 아예 이동이 불가능하면?? 그대로 있는 건가??
--> 자신이 왔던 길로 다시 돌아가면 된다.
*/
#include <iostream>
#include <vector>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 위, 아래, 왼쪽, 오른쪽
int N, M, K, curM;
struct map_shark {  // 번호, 남은 냄새, 냄새 번호
    int n, restk, sn;
    //map_shark(int _n, int _restk, int _k) : n(_n), restk(_restk), k(_k) {}
};
struct shark {      // 좌표 x, y , 냄새, 현재 방향, 우선순위
    int x, y, k, curd;
    bool live; 
    shark(int _x, int _y, int _k, int _curd, bool _live) : x(_x), y(_y), k(_k), curd(_curd), live(_live) {}
};
vector<shark> sharks;
map_shark map[21][21];
int dir_info[401][4][4]; // 상어 번호, 현재 방향, 위, 아래, 왼쪽, 오른쪽 순위

void print_map() {
    cout<<"print_map() : 상어 정보 \n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<map[i][j].n<<" ";
        }
        cout<<"\n";
    }
    cout<<"print_map() : 냄새 정보 \n";
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout<<map[i][j].restk<<" ";
        }
        cout<<"\n";
    }
}
bool simul() {

    // 상어 이동
    // 인접한 칸 중 아무 냄새가 없는 칸으로 이동
    // 그런 칸이 여러개면 정해진 우선순위 방향에 따라서 이동

    // 상어가 맨 처음에 보고 있는 방향은 입력으로 주어지고, 
    // 그 후에는 방금 이동한 방향이 보고 있는 방향이 된다.
    for(int i=1;i<=M;i++) {
        if(!sharks[i].live) continue;
        int d = sharks[i].curd;
        int x = sharks[i].x, y = sharks[i].y;
        int mx, my, tx, ty, td;
        bool find = false, check = false;
        
        //cout<<i<<"번 째 상어 정보 : d, "<< d << " x: "<<x<<" y: "<<y<<"\n";
        // 현재 상어가 가리키는 방향에 따른 우선순위 방향 정하기
        // 우선순위에 따라 냄새가 없는 지역을 먼저 찾으면 바로 그쪽으로 이동
        for(int j=0;j<4;j++) {
            int curd = dir_info[i][d][j];
            mx = x + dir[curd][0], my = y + dir[curd][1];
            if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
            if(map[mx][my].n == 0 && map[mx][my].sn != 0) {
                if(map[mx][my].sn == i && !check) {   // 현재 상어의 이전 냄새
                    // 이동할 곳이 없으면 이전 냄새로 이동
                    tx = mx;
                    ty = my;
                    td = curd;
                    check = true;
                }
                else continue;
            }
            else if(map[mx][my].n == 0) {
                find = true;
                sharks[i].curd = curd;    
                break;
            } 
        }

        if(!find) {
            sharks[i].curd = td;
            mx = tx, my = ty;
        }

        sharks[i].x = mx;
        sharks[i].y = my;
        map[x][y].n = 0;
        map[x][y].restk = sharks[i].k;
        map[x][y].sn = i;
        //cout<<i<<"번 째 상어 정보 : d, "<< sharks[i].curd << " x: "<<mx<<" y: "<<my<<"\n";
    }

    for(int i=1;i<=M;i++) {
        if(!sharks[i].live) continue;
        if(map[sharks[i].x][sharks[i].y].n == 0) {
            map[sharks[i].x][sharks[i].y].n = i;
            map[sharks[i].x][sharks[i].y].restk = K;
            map[sharks[i].x][sharks[i].y].sn = i;
        }
        else {
            sharks[i].live = false;
            curM--;
        }
    }
    
    if(curM == 1) 
        return false;

    // 전체 맵에서 남은 냄새 1씩 지우기
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            // 냄새 지우기
            if(map[i][j].n == 0 && map[i][j].restk > 0) {
                map[i][j].restk--;
                if(map[i][j].restk == 0) 
                    map[i][j].sn = 0;
            }
        }
    }
    return true;
}
void solve() {
    int answer = 1;
    //print_map();
    while(simul()) {
        //cout<<answer<<" "<<curM<<"\n";
        answer++;
        //print_map();
        if(answer > 1000) {
            answer = -1;
            break;
        }
    }
    cout << answer << "\n";
}
int main() 
{
    io;
    cin >> N >> M >> K;
    sharks.resize(M+1, shark(0, 0, 0, 0, false));
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> map[i][j].n;
            if(map[i][j].n != 0) {
                sharks[map[i][j].n].x = i;
                sharks[map[i][j].n].y = j;
                sharks[map[i][j].n].k = K;
                sharks[map[i][j].n].live = true;
            }
        }
    }

    // 상어 각각의 현재 방향
    for(int i=1;i<=M;i++) {
        cin >> sharks[i].curd;
        sharks[i].curd--;
    }

    // 상어 우선순위 입력 1 부터 M 까지
    for(int i=1;i<=M;i++) {
        for(int j=0;j<4;j++) {
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            a--, b--, c--, d--;
            // 위, 아래, 왼쪽, 오른쪽 순서
            dir_info[i][j][0] = a;
            dir_info[i][j][1] = b;
            dir_info[i][j][2] = c;
            dir_info[i][j][3] = d;
        }
    }
    curM = M;
    solve();
    return 0;
}