/*
[BOJ] 11559. Puyo Puyo
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m, ans = 50 * 50;
char map[51][51];
char start;

void solve(int x, int y){
	int cnt = 0;
	start = map[x][y];
	cout<<start<<"\n";
	for(int i=x;i<8;i++){
		for(int j=y;j<8;j++){
			if((j+i) % 2 == 0){
				if(map[i][j] != start){
					cnt++;
				}
			}else {
				if(map[i][j] == start){
					cnt++;
				}
			}
		}
	}
	ans = min(ans, cnt);
}

int main()
{
	io;
	cin>>n>>m;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<n-7;i++){
		for(int j=0;j<m-7;j++){
			solve(i, j);
		}
	}
	cout<<ans<<"\n";

	return 0;
}
