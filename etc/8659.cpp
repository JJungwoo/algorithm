/*
SWea 8659, gcd
*/
/*
#include <iostream>
using namespace std;

long long table[91][2];
int K;

void init_table() {
	table[1][0] = 2;
	table[1][1] = 1;
	for (int i = 2; i <= 90; i++) {
		table[i][1] = table[i - 1][0];
		table[i][0] = table[i - 1][0] + table[i - 1][1];
	}
}

int main()
{
	int tcase;
	cin >> tcase;

	init_table();

	for (int i = 1; i <= tcase; i++) {
		int K;
		cin >> K;
		cout << "#" << i << " " << table[K][0] <<" "<<table[K][1] << "\n";
	}
	
	return 0;
}
*/