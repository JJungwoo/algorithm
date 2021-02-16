/*
[boj] 5549. 행성 탐사
https://www.acmicpc.net/problem/5549
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// J: 정글, O: 바다, I: 얼음
int M, N, K;
int area[1001][1001][3], psum[1001][1001][3];
int main()
{
    io;
    cin >> N >> M;
    cin >> K;
    for(int i=1;i<=N;i++) {
        for(int j=1;j<=M;j++) {
            char val;
			int idx = 0;
            cin >> val;
			if (val == 'J') idx = 0;
			else if (val == 'O') idx = 1;
			else if (val == 'I') idx = 2;
			area[i][j][idx]++;
			for(int z=0;z<3;z++)
				psum[i][j][z] = area[i][j][z] - psum[i-1][j-1][z] + psum[i-1][j][z] + psum[i][j-1][z];
        }
    }

    while(K--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
		cout<<psum[x2][y2][0] - (psum[x1-1][y2][0] + psum[x2][y1-1][0] - psum[x1-1][y1-1][0])<<" ";
		cout<<psum[x2][y2][1] - (psum[x1-1][y2][1] + psum[x2][y1-1][1] - psum[x1-1][y1-1][1])<<" ";
		cout<<psum[x2][y2][2] - (psum[x1-1][y2][2] + psum[x2][y1-1][2] - psum[x1-1][y1-1][2])<<"\n";
    }

    return 0;
}
