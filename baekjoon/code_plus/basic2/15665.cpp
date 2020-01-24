/*
[BOJ] 15665. N과 M(11)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,m;
vector<int>arr;
int visited[8];
int output[8];
int hash_arr[10001];

void dfs(int cnt, int idx){

    if(cnt == m){
        for(int i=0;i<m;i++){
            cout<<output[i]<<" ";
        }
        cout<<"\n";
        return;
    }

    for(int i=idx;i<n;i++){
        output[cnt] = arr[i];
        dfs(cnt+1, i);
    }
}

int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int tmp; cin>>tmp;
        if(hash_arr[tmp] != 0)
            continue;
        hash_arr[tmp] = 1;
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    n = arr.size();
    dfs(0,0);
    return 0;
}