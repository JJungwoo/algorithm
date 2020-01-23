/*
[BOJ] 15663. N과 M(9)
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

void dfs(int cnt){

    if(cnt == m){
        /*for(int i=0;i<n;i++){
            printf("%d ", visited[i]);
        }
        printf("\n");*/
        for(int i=0;i<m;i++){
            printf("%d ", outputA[i]);
        }
        printf("\n");
        return;
    }

    int temp = 0;
    for(int i=0;i<n;i++){
        if(!visited[i] && temp != arr[i]) {
            //printf("%d, arr[%d], temp : %d\n", i, arr[i], temp);
            visited[i] = true;
            temp = arr[i];
            outputA[cnt] = arr[i];
            dfs(cnt + 1);
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
    dfs(0);

    return 0;
}