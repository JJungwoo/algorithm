/*
[BOJ] 1697. 숨바꼭질
I don't know why is output result value answer+1 
because it is visited array check.. 
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MAX = 100000;
int n,k;
queue<int> q;
int map[MAX+1];

void bfs(){
	q.push(n);
	while(!q.empty()){
		int move = q.front();
		q.pop();
		if(move == k){
			cout<<map[move]<<"\n";
			return;
		}
		int bh[] = {move-1, move+1, move*2};
		int len = sizeof(bh)/sizeof(int);
		for(int i=0;i<len;i++){
			if(bh[i] < 0 || bh[i] > MAX) continue;
			if(map[bh[i]]) continue;
			//map[bh[i]] = map[move] + 1;
			//cout<<move<<" TO "<<i<<":"<<bh[i]<<","<<map[bh[i]]<<"\n";
			q.push(bh[i]);
			map[bh[i]] = map[move] + 1;
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
