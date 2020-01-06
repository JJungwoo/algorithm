/*
[BOJ] 13549. 숨바꼭질 3
숨바꼭질3은 1과 다르게 *2한 경우 이동 횟수가 0이다. 따라서 *2의 경우에 높은 우선순위를 줘야 한다.
*/
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MAX = 100000;
int n,k;
queue<int> q;
int map[MAX+1];

void bfs(){
    q.push(n);
    while(!q.empty()){
        int x = q.front(); 
        q.pop();
        if(x == k){
            cout<<map[x]<<"\n";
            return;
        }
        int bh[] = {x-1, x+1, x*2};
        for(int i=0;i<3;i++){
            if(bh[i] < 0 || bh[i] > MAX) continue;
            if(map[bh[i]]) continue;
            q.push(bh[i]);
            if(i==2) map[bh[i]] = map[x];
            else map[bh[i]] = map[x] + 1;
        }
    }
}

int main()
{
    io;
    cin>>n>>k;
    bfs();

    return 0;
}   