/*
[BOJ] 15656. N과 M(7)
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX =  8;
int n,m;
int outputA[MAX+1];
vector<int> arr;

void dfs(int cnt){

    if(cnt == m){
        for(int i=0;i<m;i++){
            printf("%d ", outputA[i]);
        }
        printf("\n");
        return;
    }

    for(int i=0;i<n;i++){
        outputA[cnt] = arr[i];
        dfs(cnt+1);
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
