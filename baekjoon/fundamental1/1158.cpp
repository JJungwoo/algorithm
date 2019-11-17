/*
[BOJ] 1158. 조세퍼스 문제
https://www.acmicpc.net/problem/1158
*/
/*
#include <cstdio>
#include <vector>

using namespace std;
int main()
{
	int n, k, cnt = 0, idx = 0;
	scanf("%d %d", &n, &k);
	vector<int> person(n);
	for (int i = 0; i < n; i++) {
		person[i] = i+1;
	}
	printf("<");
	while (cnt < n) {
		idx = (idx + k-1)%person.size();
		printf("%d", person[idx]);
		if(cnt+1 != n)
			printf(", ");
		person.erase(person.begin() + idx);
		cnt++;
	}
	printf(">\n");

	return 0;
}
*/