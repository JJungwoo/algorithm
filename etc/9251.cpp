/*
#include <iostream>
#include <string>
using namespace std;

#define min(a,b)(a<b?a:b)
#define max(a,b)(a>b?a:b)
int lcs[1000][1000];

int main()
{
	string tmp1, tmp2;
	cin >> tmp1 >> tmp2;

	cout << tmp1.size() << ", " << tmp2.size() << '\n';
	
	if (tmp1.size() == 1 && tmp2.size() == 1)
	{
		if (tmp1[0] == tmp2[0]) cout << "1\n";
		else cout << "0\n";
		return 0;
	}
	for (int i = 1; i <= tmp1.size(); i++) {
		for (int j = 1; j <= tmp2.size(); j++) {
			if (tmp1[i] == tmp2[j]) {
				lcs[j][i] = lcs[j - 1][i - 1] + 1;
				cout <<lcs[j][i]<< tmp1[i] << ", " << tmp2[j] << '\n';
			}
			else {
				lcs[j][i] = max(lcs[j - 1][i], lcs[j][i - 1]);
			}
		}
	}

	for (int i = 0; i <= tmp1.size(); i++) {
		for (int j = 0; j <= tmp2.size(); j++) {
			cout << lcs[j][i];
		}
		cout << '\n';
	}
	int pos = min(tmp1.size(), tmp2.size());
	cout <<pos<<":"<< lcs[pos][pos] << '\n';
	return 0;
}
*/