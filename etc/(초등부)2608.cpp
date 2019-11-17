/*
[BOJ] 
https://www.acmicpc.net/problem/
*

#include <iostream>
#include <string.h>
using namespace std;

struct ro_table {
	int value;
	char word;
};

struct ex_ro_table {
	int value;
	char *word;
};

struct ro_table rt[7] = 
{ {1, 'I'}, {5,'V'}, {10,'X'},
{50,'L'}, {100,'C'}, {500,'D'}, 
{1000,'M'} };

struct ex_ro_table ex_rt[6] =
{ { 4, "IV" },{ 9,"IX" },{ 40,"XL" },
{ 90, "XC" },{ 400, "CD" },{ 900, "CM" } };

int rtoa(char *str, int len) {
	int i = 0;
	int ret = 0;
	while (str[i]) {
		for (int j = 0; j < 7; j++) {
			if (str[i] == rt[j].word) {
				if (i < len && (j == 0 || j == 2 || j == 4)) {
					if (str[i] == ex_rt[j].word[0] && str[i+1] == ex_rt[j].word[1]) {
						ret += ex_rt[j].value;
						i += 2;
						break;
					}
					else if (str[i] == ex_rt[j + 1].word[0] && str[i + 1] == ex_rt[j + 1].word[1]) {
						ret += ex_rt[j + 1].value;
						i += 2;
						break;
					}
					else {
						ret += rt[j].value;
						i += 1;
						break;
					}
				}
				else {
					ret += rt[j].value;
					i += 1;
					break;
				}
			}
		}
	}
	return ret;
}

char *ator(int num) {

	while (num) {
		printf("%d %d\n", num , num % 10);


		 

		num /= 10;
	}


	return NULL;
}

int main()
{
	char str1[2000] = { '\0', };
	char str2[2000] = { '\0', };
	int num_ans = 0;
	int i = 0;

	scanf("%s %s", &str1, &str2);
	
	//num_ans += rtoa(str1, strlen(str1));
	//num_ans += rtoa(str2, strlen(str2));
	num_ans = 2493;
	printf("%d\n", num_ans);

	ator(num_ans);

	return 0;
}
*/