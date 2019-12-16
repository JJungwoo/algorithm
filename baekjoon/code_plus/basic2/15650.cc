/*
[BOJ] 15650. N과 M(2)
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

    for(int i=idx;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            arr[cnt] = i+1;
            dfs(i, cnt+1);    
            visited[i] = false;        
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    dfs(0,0);
    return 0;
}