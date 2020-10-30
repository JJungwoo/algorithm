/*
[boj] 19237. 어른 상어 
https://www.acmicpc.net/problem/19237
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // 0부터 위, 아래, 왼, 오
int N, M, K;
int prefermove[401][4][4], field[21][21];
struct map{
    int rest, owner;
};
map maps[21][21];
vector<pair<int, int> > sharks[21][21]; // num, dir
vector<pair<int, int> > spos;
void print_map(int s) {
    if(s == 1) {
        cout<<" \n";
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(sharks[i][j].size() > 0) 
                    cout<<sharks[i][j][0].first<<" ";
                else 
                    cout<<sharks[i][j].size()<<" ";
            }
            cout<<"\n";
        }
    }
    else {
        cout<<" \n";
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cout<<maps[i][j].rest<<" ";
            }
            cout<<"\n";
        } 
    }
}
bool check_success() {
    int sum = 0;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            sum += sharks[i][j].size();
        }
    }
    if(sum == 1) 
        return true;
    return false;
}
void move_sharks() {
    vector<pair<int, int> > tmp[21][21];
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(sharks[i][j].size() > 0) {                
                int n = sharks[i][j][0].first, d = sharks[i][j][0].second;
                int tx = -1, ty = -1, td = -1;
                bool check = false;
                for(int z=0;z<4;z++) {
                    int mx = i + dir[prefermove[n][d][z]][0], my = j + dir[prefermove[n][d][z]][1];
                    if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
                    if(maps[mx][my].rest > 0) {
                        if(tx == -1 && maps[mx][my].owner == n) {
                            tx = mx, ty = my, td = prefermove[n][d][z];
                        }
                        else continue;
                    } 
                    else if(maps[mx][my].owner == 0) {
                        tmp[mx][my].push_back(make_pair(n, prefermove[n][d][z]));
                        check = true;
                        break;
                    }
                }
                if(!check && tx != -1 && ty != -1 && td != -1) {
                    tmp[tx][ty].push_back(make_pair(n, td));
                }
            } 
        }
    }
    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            sharks[i][j] = tmp[i][j];
        }
    }
}
void smellcheck_and_delsharks() {

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if(maps[i][j].rest > 0) {
                maps[i][j].rest--;
                if(maps[i][j].rest == 0) {
                    maps[i][j].owner = 0;
                }
            }
            if(sharks[i][j].size() > 1) {
                sort(sharks[i][j].begin(), sharks[i][j].end());
                sharks[i][j].erase(sharks[i][j].begin() + 1, sharks[i][j].end());
                maps[i][j].owner = sharks[i][j][0].first;
                maps[i][j].rest = K;
            }else if(sharks[i][j].size() == 1){
                maps[i][j].owner = sharks[i][j][0].first;
                maps[i][j].rest = K;
            }
        }
    }
}
void solve() {
    int answer = -1;
    for(int i=1;i<1000;i++) {
        move_sharks();
        smellcheck_and_delsharks();
        print_map(0);
        if(check_success()) {
            answer = i;
            break;
        }
    }
    cout<<answer<<"\n";
}
int main() 
{
    io;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> field[i][j];
            if(field[i][j] != 0) {
                sharks[i][j].push_back(make_pair(field[i][j], 0));
                spos.push_back(make_pair(i, j));
                maps[i][j].owner = field[i][j];
                maps[i][j].rest = K;
            }
        }
    }
    for(int i=0;i<M;i++) {
        cin >> sharks[spos[i].first][spos[i].second][0].second;
        sharks[spos[i].first][spos[i].second][0].second--;
    }
    for(int i=1;i<=M;i++) {  // 상어 번호
        for(int j=0;j<4;j++) {  // 상어 우선순위 대
            for(int d=0;d<4;d++){   // 상어 우선순위 소
                cin >> prefermove[i][j][d];
                prefermove[i][j][d]--;
            }
        }
    }
    solve();
    return 0;
}