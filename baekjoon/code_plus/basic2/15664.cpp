/*
[BOJ] 15664. N과 M(10)
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

void dfs(int cnt){

    if(cnt == m){
        for(int i=0;i<m;i++){
            cout<<output[i]<<" ";
        }
        cout<<"\n";
    }

    int temp = 0;
    for(int i=0;i<n;i++){
        if(!visited[i] && temp != arr[i]){
            visited[i] = true;
            temp = arr[i];
            output[i] = arr[i];
            dfs(cnt+1);
            visited[i] = false;
        }
    }
}

int main()
{
    io;
    cin>>n>>m;
    for(int i=0;i<n;i++) {
        int tmp; scanf("%d", &tmp);
        arr.push_back(tmp);
    }
    sort(arr.begin(), arr.end());
    dfs(0);
    return 0;
}