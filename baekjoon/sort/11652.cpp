/*
[boj] 11652. 카드
https://www.acmicpc.net/problem/11652
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
int main()
{
    io;
	int N; cin >> N;
	vector<ll> v(N);
	for(int i=0;i<N;i++) {
		cin >> v[i];
	}
	sort(begin(v), end(v));
	ll ans = v[0];
	int cnt = 1, max_cnt = 0;
	for(int i=1;i<v.size();i++) {
		if (v[i] == v[i-1]) {
			cnt++;
			if(cnt > max_cnt) {
				max_cnt = cnt;
				ans = v[i];
			}
		}else
			cnt = 1;
	}
	cout<<ans<<"\n";
    return 0;
}
