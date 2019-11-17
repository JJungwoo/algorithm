/*
[BOJ] 2745. 진법 변환
https://www.acmicpc.net/problem/2745
*/
/*
#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;

int atoi(char tmp) {
	int val = 0;
	if (tmp >= '0' && tmp <= '9') {
		val = tmp - '0';
	}
	else val = tmp - 'A' + 10;
	return val;
}

int pow(int val, int mul) {
	int result = 1;
	for (int i = 0; i < mul; i++) {
		result *= val;
	}
	return result;
}

int main()
{
	vector<char> v;
	string n;
	int b, mul_cnt = 0, i = 0;
	ll ans = 0;
	cin >> n >> b;
	mul_cnt = n.size()-1;
	while (!n.empty()) {
		ans += atoi(n[mul_cnt]) * pow(b,i);
		n.pop_back();
		mul_cnt--;
		i++;
	}
	cout << ans << endl;

	return 0;
}
*/