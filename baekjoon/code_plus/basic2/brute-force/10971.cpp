/*
[BOJ] 10971. 외판원 순회 2
*/

#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans = 1e9;
int w[11][11];
bool visited[11];

void dfs(int move, int idx, int value, int cnt){
    if(move == idx && cnt == n){
        //cout<<"end: "<<ans<<" , "<< value<<"\n";
        if(ans > value) ans = value;
        return;
    }
    for(int i=0;i<n;i++) {
        if(w[move][i] == 0) continue;
        if(visited[i] == true) continue;
        visited[i] = true;
        value += w[move][i];
        //cout<<i<<" <- "<<move<<" start: "<<idx<<" , "<< value <<", "<<cnt<<"\n";
        dfs(i, idx, value, cnt + 1);
        visited[i] = false;
        value -= w[move][i];
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>w[i][j];
        }
    }

    for(int i=0;i<n;i++){
        dfs(i, i, 0, 0);
    }
    //dfs(0,0,0,0);
    cout<<ans<<"\n";
    return 0;
}