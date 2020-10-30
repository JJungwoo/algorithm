/*
[boj] 16235. 나무 재테크
https://www.acmicpc.net/problem/16235
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int dir[8][2] = { {-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1} };
int N, M, K;
struct wood{
    int x, y, age;
    wood(int _x, int _y, int _age) : x(_x), y(_y), age(_age) {}
};
int mineral[11][11], map[11][11];    // 양분
vector<int> woods[11][11];  // 낮은 값이 앞으로 오도록 -val로 푸시하기 (어린 나무 우선순위)

void simul() {
    vector<wood> craetewoods; // 죽은 나무, 새로 자라는 나무
    // 봄
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            sort(woods[i][j].begin(), woods[i][j].end());
            int idx = 0;
            bool check = false;
            for(int z=0;z<woods[i][j].size();z++) {
                int value = woods[i][j][z];
                if(value > map[i][j]) {
                    idx = z;
                    check = true;
                    break;
                }else{
                    map[i][j] -= value;
                    woods[i][j][z] = value + 1;

                    if(value+1 > 4 && (value+1)%5 == 0) {
                        for(int d=0;d<8;d++) {
                            int mx = i + dir[d][0], my = j + dir[d][1];
                            if(mx < 0 || my < 0 || mx >= N || my >= N) continue;
                            craetewoods.push_back(wood(mx, my, 1));
                        } 
                    }
                }
            }
            
            if(check) {
                // 여름
                for(int z=idx;z<woods[i][j].size();z++) {
                    map[i][j] += woods[i][j][z] / 2;
                }
                woods[i][j].erase(woods[i][j].begin() + idx, woods[i][j].end());
            }

            // 겨울 각각의 토지에 양분 더하기
            map[i][j] += mineral[i][j];
        }
    }

    // 가을
    for(auto it : craetewoods) {
        woods[it.x][it.y].push_back(it.age);
    }
}

void solve() {
    int answer = 0;
    while(K--) 
        simul();
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            answer += woods[i][j].size();
        }
    }
    cout << answer << "\n";
}
int main() 
{
    io;
    cin >> N >> M >> K;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> mineral[i][j];
            map[i][j] = 5;
        }
    }

    for(int i=0;i<M;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        woods[x][y].push_back(z);
    }
    solve();
    return 0;
}