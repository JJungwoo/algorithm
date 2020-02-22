/*
[BOJ] 14889. 스타트와 링크
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, min_ans = 200;
int team[21][21];
bool visited[21];

void dfs(int idx, int cnt){
    if(idx == n) return;
    if(cnt == n/2){
        int sum1 = 0, sum2 = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(visited[i] && visited[j]) sum1 += team[i][j];
                if(!visited[i] && !visited[j]) sum2 += team[i][j];
            }
        }
        int sum = abs(sum1 - sum2);
        min_ans = min_ans > sum ? sum : min_ans;
        return;
    }

    visited[idx] = true;
    dfs(idx+1, cnt+1);
    visited[idx] = false;
    dfs(idx+1, cnt);
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>team[i][j];
        }
    }
    
    dfs(0, 0);
    cout<<min_ans<<"\n";

    return 0;
}