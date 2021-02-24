/*
[boj] 2026. 소풍
https://www.acmicpc.net/problem/2026
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int K, N, F;
bool relation[901][901];
int main()
{
	io;
	cin >> K >> N >> F;
	for(int i=0;i<F;i++) {
		int A, B;
		cin >> A >> B;
		relation[A][B] = relation[B][A] = 1;
	}

	vector<int> v;
	for(int i=1;i<=N;i++)
		v.push_back(i);
	do{
		bool ispossible = true;
		for(int i=0;i<K-1;i++) {
			//cout<<v[i]<<" ";
			for(int j=i+1;j<K;j++) {
				if(!relation[v[i]][v[j]]) {
					//cout<<"\n";
					ispossible = false;
					break;
				}
			}
		}
		if(ispossible == true) {
			sort(v.begin(), v.begin()+K);
			for(int i=0;i<K;i++) {
				cout<<v[i]<<"\n";
			}
			return 0;
		}
	}while(next_permutation(begin(v), end(v)));
	cout<<"-1\n";
	return 0;
}
/*
vector<int> v[901], ans;
bool relation[901][901], ispossible;
map<int, int> m;
int K, N, F;
void find(int pos) {
	ans.push_back(pos);
	if(ans.size() == K) {
		ispossible = true;
		return;
	}
	for(auto nxt : v[pos]) {
		for(auto it : ans)
			if(!relation[nxt][it]) return;
		find(nxt);
	}
	ans.pop_back();
}
int main()
{
    io;
	cin >> K >> N >> F;
	for(int i=0;i<F;i++) {
		int A, B; cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
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
*/
