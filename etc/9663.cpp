/*
[BOJ] 2947번: 나무 조각
*/
/*
#include <iostream>
using namespace std;

int main()
{
	int piece[5], chk = 0;
	for (int i = 0; i < 5; i++)
		cin >> piece[i];
	while (!chk) {
		for (int i = 0; i < 4; i++) {
			if (piece[i] > piece[i+1]) {
				swap(piece[i], piece[i+1]);
				for (int z = 0; z<5; z++)
					cout << piece[z] << " ";
				cout << endl;
			}	
		}
		chk = 1;
		for (int i = 0; i < 5; i++)
			if (piece[i] != i + 1)
				chk = 0;
	}
	
	return 0;
}
*/