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
		int mx = x + dir[i][0], my = y + dir[i][0];
		if(mx < 0 || my < 0 || mx >= n || my >= m) return false;
		if(visited[mx][my]) return false;

	}
	return true;
}

void dfs(int x, int y, int cnt)
{
	if(cnt == n){
		ans++;
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(visited[i][j]) continue;
			if(move_check == false) continue;			
			visited[i][j] = true;
			dfs(i, j, cnt+1);
			visited[i][j] = false;
		}
	}
		

}

int main()
{
        io;
        cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
        		dfs(i, j, 1);
				memset(visited, 0, sizeof(visited));
			}
		}
		cout<<ans<<"\n";

        return 0;
}

