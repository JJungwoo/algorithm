/*
[BOJ] 15654. N과 M(5)
*/
#include <cstdio>
using namespace std;
const int max = 8;
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
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = n+i;
            dfs(i, cnt+1);
            visited[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    dfs(0, 0);
    return 0;
}