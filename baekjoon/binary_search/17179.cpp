/*
[boj] 17179. 케이크 자르기
https://www.acmicpc.net/problem/17179
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, L;
vector<int> cake;
bool do_cut(int mid, int cut) {
	int tmp = 0;
	for(int i=0;i<=M;i++) {
		if(cake[i] - tmp >= mid) {
			cut--;
			tmp = cake[i];
		}
	}
	return cut < 0 ? true : false;
}
int main()
{
    io;
	cin >> N >> M >> L;
	cake.resize(M+1);
	for(int i=0;i<M;i++) {
		cin >> cake[i];
	}
	cake[M] = L;
	for(int i=0;i<N;i++) {
		int cut, ans = 0;
		cin >> cut;
		int left = 0, right = cake[M];
		while(left <= right) {
			int mid = (left + right)/2;
			if(do_cut(mid, cut)) {
				left = mid + 1;
				ans = max(ans, mid);
			} else {
				right = mid - 1;
			}
		}
		cout<<ans<<"\n";
	}

    return 0;
}
