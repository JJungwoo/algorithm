/*
[BOJ] 15649. N과 M
*/
#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 8;
int n,m;
int arr[MAX+1];
bool visited[MAX+1];

void dfs(int cnt)
{
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
            arr[cnt] = i+1;
            dfs(cnt+1);
            visited[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    dfs(0);
    return 0;
}
