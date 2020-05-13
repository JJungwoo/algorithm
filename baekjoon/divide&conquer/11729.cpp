/*
[boj] 11729. 하노이 탑 이동 순서
한 번에 한 개의 원판만을 다른 탑으로 옮길 수 있다.
쌓아 놓은 원판은 항상 위의 것이 아래의 것보다 작아야 한다.
하노이 탑 귀납법: 2n - 1
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, k;
void hanoi(int n, int a, int b) {
	if (n == 0) return;

	hanoi(n - 1, a, 6 - a - b);
	cout << a << " " << b << "\n";
	hanoi(n - 1, 6 - a - b, b);
}
int main()
{
	io;
	cin >> n;
	
	cout << (1<<n) - 1 << "\n";
	
	hanoi(n, 1, 3);
	
	return 0;
}
