/*
[BOJ] 11005. 진법 변환2
https://www.acmicpc.net/problem/11005
*/
/*
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main()
{
	ll n, b;
	vector<int> v;
	scanf("%lld %lld", &n, &b);
	while (n > b) {
		v.push_back(n % b);
		n /= b;
	}
	if (n % b == 0) {
		v.push_back(0);
		v.push_back(n / b);
	}
	else
		v.push_back(n);
	for (int i = v.size()-1; i>=0; --i) {
		if (v[i] > 9)
			printf("%c", v[i]+55);
		else 
			printf("%d", v[i]);
	}
	printf("\n");

	return 0;
}
*/