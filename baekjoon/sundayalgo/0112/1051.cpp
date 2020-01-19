/*
[BOJ] 1051. 숫자 정사각형
*/
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, ans;
int map[51][51];

void find_dff(int x, int y) {
    for(int i=y+1;i<m;i++){
        int diff = i - y;
        if(y+diff >= m || x+diff >= n) continue;
        if(map[x][y] == map[x][i] && map[x][y] == map[x + diff][y + diff] 
            && map[x][y] == map[x + diff][y]){
            ans = max(ans, (diff+1)*(diff+1));
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            find_dff(i, j);
        }
    }
    if(!ans) printf("1\n");
    else printf("%d\n",ans);
    
    return 0;
}