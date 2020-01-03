/*
[BOJ] 2667. 단지번호붙이기
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, cnt;
int map[25][25];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
vector<int> ans;
void dfs(int x, int y)
{
    map[x][y] = 0;
    cnt++;
    for(int i=0;i<4;i++){
        int mx = x + dir[i][0], my = y + dir[i][1];
        if(mx < 0 || mx >= n || my < 0 || my >= n) continue;
        if(!map[mx][my]) continue;
        dfs(mx, my);
    }
}

int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d", &map[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]){
                cnt = 0;
                dfs(i, j);
                ans.push_back(cnt);
            }
        }
    }
    sort(ans.begin(), ans.end());
    int len = ans.size();
    printf("%d\n", len);
    for(int i=0;i<ans.size();i++){
        printf("%d\n", ans[i]);
    }

    return 0;
}