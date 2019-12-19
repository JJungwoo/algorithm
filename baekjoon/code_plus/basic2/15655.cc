
/*
[BOJ] 15655. N과 M(6)
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX =  8;
int n,m;
bool visited[MAX+1];
int outputA[MAX+1];
vector<int> arr;

void dfs(int idx, int cnt){

    if(cnt == m){
        for(int i=0;i<m;i++){
            printf("%d ", outputA[i]);
        }
        printf("\n");
        return;
    }

    for(int i=idx;i<n;i++){
        if(!visited[i]){
            visited[i] = true;
            outputA[cnt] = arr[i];
            dfs(i, cnt+1);
            visited[i] = false;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) {
        int tmp; scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    dfs(0,0);

    return 0;
}
