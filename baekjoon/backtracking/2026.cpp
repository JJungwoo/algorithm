/*
[boj] 2026. 소풍
https://www.acmicpc.net/problem/2026
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
bool relation[901][901], ispossible;
vector<int> ans;
int K, N, F;
void find(int pos) {
	ans.push_back(pos);
	if(ans.size() == K) {
		ispossible = true;
		return;
	}
	for(int i=pos+1;i<=N;i++) {
		bool check = true;
		if(!relation[pos][i]) continue;
		for(auto it : ans)
			if(!relation[i][it]) {
				check = false;
				break;
			}
		if(check)
			find(i);
		if(ispossible) return;
	}
	ans.pop_back();
}
int main()
{
    io;
	cin >> K >> N >> F;
	for(int i=0;i<F;i++) {
		int A, B; cin >> A >> B;
		relation[A][B] = relation[B][A] = 1;
	}

	for(int i=1;i<=N;i++) {
		find(i);
		if(ispossible) {
			for(auto it : ans) {
				cout<<it<<"\n";
			}
			return 0;
		}
	}

	cout<<"-1\n";
    return 0;
}
