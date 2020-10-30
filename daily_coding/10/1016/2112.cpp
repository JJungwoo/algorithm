/*
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int T, D, W, K;
int map[14][21];
bool visited[14], success;
vector<pair<int, int> > sel;
bool check_success(int target[14][21]) {
    for(int j=0;j<W;j++) {
        int maxcnt = 0, tmp = target[0][j], cnt = 1;
        for(int i=1;i<D;i++) {
            if(tmp == target[i][j]) cnt++;
            else {
                maxcnt = max(maxcnt, cnt);
                cnt = 1;   
                tmp = target[i][j];
            }
        }
        maxcnt = max(maxcnt, cnt);
        if(maxcnt < K)
            return false;
    }
    return true;
}
void copy_map(int dest[14][21]) {
    for(int i=0;i<D;i++) {
        for(int j=0;j<W;j++) {
            dest[i][j] = map[i][j];
        }
    }
}
// 현재까지의 마지막 선택 위치, 현재까지 선택한 갯수, 전체 선택할 갯수
void dfs(int idx, int cnt, int stand) {
    if(success || cnt > K) return;
    if(cnt == stand) {
        int tmp[14][21];
        copy_map(tmp);
        for(int i=0;i<sel.size();i++) {
            for(int j=0;j<W;j++) {
                tmp[sel[i].first][j] = sel[i].second;
            }
        }
        if(check_success(tmp))
            success = true;
        return ;
    }
    for(int i=idx;i<D;i++) {
        if(visited[i]) continue;
        visited[i] = true;
        for(int j=0;j<2;j++) {
            sel.push_back(make_pair(i, j));
            dfs(i+1, cnt+1, stand);
            sel.pop_back();
        }        
        if(success) return;
        visited[i] = false;
    }
}
bool solve(int cnt) {
    for(int i=0;i<D;i++) {
        if(visited[i]) continue;
        visited[i] = true;
        for(int j=0;j<2;j++) {
            sel.push_back(make_pair(i, j));
            dfs(i, 1, cnt);
            if(success)
                return true;
            sel.pop_back();
        }
        visited[i] = false;
    }
    return false;
}
int main() 
{
    io;
    cin >> T;
    while(T--) {
        success = false;
        sel.clear();
        cin >> D >> W >> K;
        memset(visited, false, sizeof(visited));
        for(int i=0;i<D;i++) {
            for(int j=0;j<W;j++) {
                cin >> map[i][j];
            }
        }
        if(K == 1 || check_success(map)) {
            cout<<"0\n";
        }else{
            for(int i=2;i<=K;i++) {
                if(solve(i)) {
                    cout<<i<<"\n";
                    break;
                }
            }
        }
    }
    return 0;
}

