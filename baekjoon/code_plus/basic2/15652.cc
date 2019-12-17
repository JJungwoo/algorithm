/*
[BOJ] 15652. N과 M(4)
*/
#include <cstdio>
using namespace std;
const int max = 8;
int n,m;
int arr[max+1];

void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i=0;i<m;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=idx;i<n;i++){
        arr[cnt] = i+1;
        dfs(i, cnt+1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    dfs(0,0);
    return 0;
}