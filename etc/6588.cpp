/*
baekjoon 6588번 골드바흐의 추측
*/

/*
#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	int a = 1, b = 0;
	bool chk = false;
	do{
		cin >> n;
		if (n > 0) {
			a = 1, chk = false;
			cout << "hello program" << endl;
			if (n % 2 == 0)
				b = n - 1;
			else 
				b = n;
			while (!chk) {
				if (a + b == n)
					chk = true;
				else if (a >= b)
					break;
				b -= 2;
				if (a + b == n)
					chk = true;
				else if (a >= b)
					break;
				a += 2;
			}
			if (chk == true)
				cout << n << " = " << a << " + " << b << endl;
			else
				cout << "Goldbach's conjecture is wrong." << endl;
		}
	} while (n);

	return 0;
}

*/