/*
[BOJ] 9663. N-Queen
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans;
bool visited[16][16];
int dir[8][2] = 
{
	{-1,-1}, {-1,0}, {-1,1},
	{0, -1}, {0, 1},
	{1, -1}, {1, 0}, {1 ,1}
};

bool move_check(int x, int y)
{
	for(int i=0;i<8;i++){
		int mx = x, my = y;
		while(1){
			//cout<<"mx: "<<mx<<" my: "<<my<<"\n";
			mx += dir[i][0];
			my += dir[i][1];
			if(mx < 0 || my < 0 || mx >= n || my >= n) break;
			if(visited[mx][my]) return false;
		}
	}
	return true;
}

void dfs(int x, int y, int cnt)
{
	if(cnt == n+1){
		ans++;
		return;
	}

	//for(int i=x;i<n;i++){
		for(int j=0;j<n;j++){
			if(visited[x][j]) continue;
			if(move_check(x, j) == false) continue;
			//cout<<x<<":"<<j<<"\n";
			visited[x][j] = true;
			dfs(x+1, j, cnt+1);
			visited[x][j] = false;
		}
	//}
}

int main()
{
        io;
        cin>>n;
		for(int i=0;i<n;i++){
			//for(int j=0;j<n;j++){
        		dfs(0, i, 1);
				memset(visited, 0, sizeof(visited));
			//}
		}
		cout<<ans<<"\n";

        return 0;
}

