/*
[BOJ] 1991. 트리 순회
https://www.acmicpc.net/problem/1991
*/
/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	vector<pair<char, pair<int, char> > > tree;

	while (n--) {
		char a, b, c;
		scanf("%c %c %c", &a, &b, &c);
		tree.push_back(make_pair(a, make_pair(0, b)));
		tree.push_back(make_pair(a, make_pair(1, c)));
	}

	return 0;
}
*/