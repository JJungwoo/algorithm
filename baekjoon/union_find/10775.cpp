/*
[boj] 10775. °øÇ×
*/

#include <iostream>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int parent[100011];
int g, p, ans;

void init() {
	for (int i = 1; i <= g; i++) {
		parent[i] = i;
	}
}

int find(int p) {
	if (parent[p] == p) return p;
	else return parent[p] = find(parent[p]);
}

int main()
{
	io;
	cin >> g >> p;
	init();
	for (int i = 0; i < p; i++) {
		int input; 
		cin >> input;
		int tmp = find(input);
		if (tmp == 0) break;
		ans++;
		parent[tmp] = tmp - 1;
	}
	cout << ans << "\n";
	return 0;
}