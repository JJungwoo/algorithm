/*
[BOJ] 15651. N과 M(3)
*/
#include <cstdio>
using namespace std;
const int max = 7;
int n,m;
int arr[max+1];
bool visited[max+1];

void dfs(int idx, int cnt){
    if(cnt == m){
        for(int i=0;i<m;i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
        return;
    }

    for(int i=0;i<n;i++){
        arr[cnt] = i+1;
        dfs(idx, cnt+1);
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    dfs(0, 0);
    return 0;
}