/*
[boj] 
https://www.acmicpc.net/problem/
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define END 9
vector<pair<int, int> > v;
bool endcheck, visited[3][3][END+1];
void backtracking(int cnt, int tmp[END+1][END+1]) {
    if(endcheck) return;
    if(cnt == v.size()) {
        cout<<"end\n";
        endcheck = true;
        for(int i=1;i<=END;i++){
            for(int j=1;j<=END;j++) {
                cout << tmp[i][j] << " ";
            }
            cout<<"\n";
        }
        return ;
    }

    for(int i=1;i<=END;i++) {
        bool check = false;
        int x = v[cnt].first, y = v[cnt].second;
        for(int j=1;j<=END;j++) {
            if(tmp[x][j] == i || tmp[j][y] == i || visited[x/3][y/3][i]) {
                check = true;
                break;
            }
        }
        if(check) continue;
        tmp[v[cnt].first][v[cnt].second] = i;
        visited[x/3][y/3][i] = true;
        backtracking(cnt + 1, tmp);
        visited[x/3][y/3][i] = false;
        tmp[v[cnt].first][v[cnt].second] = 0;
    }
}

int main() 
{
    io;
    int map[END+1][END+1];
    for(int i=1;i<=END;i++){
        for(int j=1;j<=END;j++) {
            cin >> map[i][j];
            if(map[i][j] == 0) {
                v.push_back(make_pair(i, j));
            }
        }
    }
    backtracking(0, map);
    return 0;
}