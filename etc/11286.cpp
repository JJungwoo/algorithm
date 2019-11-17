/*
[BOJ] 11286 Àý´ë°ª Èü
*/

/*
#include <iostream>
#include <algorithm>
#include <queue>

#pragma warning(disable:4996)
using namespace std;

priority_queue<pair<int, int>> pq;
int n, x;

int main() {
	for (scanf("%d", &n); n--;) {
		scanf("%d", &x);
		if (x) pq.push({ -abs(x), -x });
		else if (pq.empty()) printf("0\n");
		else printf("%d\n", -pq.top().second), pq.pop();
	}
	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
#include <queue>

#pragma warning(disable:4996)
using namespace std;

priority_queue<pair<int, int>> pq;
int n, x;

int main() {
	for (scanf("%d", &n); n--;) {
		scanf("%d", &x);
		if (x) pq.push({-abs(x), -x});
		else if (pq.empty()) printf("0\n");
		else printf("%d\n", -pq.top().second), pq.pop();
	}
	return 0;
}
*/