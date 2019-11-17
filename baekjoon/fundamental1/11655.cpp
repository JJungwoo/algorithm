/*
[BOJ] 11655. ROT13
https://www.acmicpc.net/problem/11655
*/
/*
#include <iostream>
using namespace std;
int main()
{
	int idx = 0;
	int buf[100] = { '\0', };
	char tmp = NULL;
	while (1) {
		scanf("%c", &tmp);
		if (tmp == '\n')
			break;
		if ((65 <= tmp && 90 >= tmp))
			buf[idx] = (((tmp + 13) % 65) % 26) + 65;
		else if ((97 <= tmp && 122 >= tmp))
			buf[idx] = (((tmp + 13) % 97) % 26) + 97;
		else buf[idx] = tmp;
		idx++;
	}
	for (int i = 0; i < idx; i++)
		printf("%c", (char)buf[i]);
	printf("\n");

	return 0;
}
*/