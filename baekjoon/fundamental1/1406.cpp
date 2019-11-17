/*
[BOJ] 1406. ¿¡µðÅÍ
https://www.acmicpc.net/problem/1406
*/
/*
#include <cstdio>
using namespace std;
int main()
{
	int bsize = 0;
	char tmp = NULL;
	char buffer[100001] = { '\0', };
	while (scanf("%c", &tmp)) {
		if (tmp == '\n') break;
		buffer[bsize++] = tmp;
	}
	int t, cursor = bsize;
	scanf("%d", &t);
	while (t--) {
		char option = NULL;
		if (option == 'P') {
			char in_char = NULL;
			scanf("%c", &in_char);
			if (cursor > bsize / 2) // back input
			{

			}
			else {

			}
		}
	}


	return 0;
}
*/
/*
#include <cstdio>
#include <deque>
using namespace std;
int main()
{
	char tmp = NULL;
	deque<char> cdq;
	while (scanf("%c", &tmp)) {
		if (tmp == '\n') break;
		cdq.push_back(tmp);
	}
	int t, idx = cdq.size();
	scanf("%d", &t);
	while (t--) {
		char option = NULL;
		if (option == 'P') {
			char in_char = NULL;
			scanf("%c", &in_char);
			if (idx > cdq.size() / 2) // back input
			{

			}
			else {

			}
		}
	}


	return 0;
}
*/

/*
#include <cstdio>
#include <stack>
using namespace std;

int main() {
	char tmp = NULL;
	stack<char> cst;
	while (scanf("%c", &tmp)) {
		if (tmp == '\n') break;
		cst.push(tmp);
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		char option = NULL;
		if (option == 'P') {
			char in_char = NULL;
			scanf("%c", &in_char);
			cst.push(in_char);
		}
	}

	return 0;
}
*/