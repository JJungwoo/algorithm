/*
[BOJ] 15657. N과 M(9)
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
int hash_arr[MAX+1];

void dfs(int cnt){

    if(cnt == m){
        for(int i=0;i<m;i++){
//            if(!visited[arr[i]]) {
                printf("%d ", outputA[i]);
//            }
        }
        printf("\n");
        return;
    }

    for(int i=0;i<n;i++){
        if(hash_arr[arr[i]]) {
            hash_arr[arr[i]]++;
            visited[i] = true;
            outputA[cnt] = arr[i];
            dfs(cnt + 1);
            hash_arr[arr[i]]--;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for(int i=0;i<n;i++) {
        int tmp; scanf("%d", &tmp);
        arr.push_back(tmp);
        if(!hash_arr[tmp]) hash_arr[tmp] = 1;
    }
    sort(arr.begin(), arr.end());
    dfs(0);

    return 0;
}