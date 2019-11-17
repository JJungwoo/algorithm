/*
Light OJ 1112. Curious Robin Hood
http://www.lightoj.com/volume_showproblem.php?problem=1112
*/
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<int> tree;

int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i & -i);
	}
	return ans;
}



int main()
{
	int a = 10;
	

	cout << a << " : "<<bitset<32>(a) << "\n";
	a = ~a;
	cout << a << " : " << bitset<32>(a) << "\n";
	a = a << 16;
	cout << a << " : " << bitset<32>(a) << "\n";


	return 0;
}
