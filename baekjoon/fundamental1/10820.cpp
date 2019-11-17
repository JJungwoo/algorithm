/*
[BOJ] 10820. 문자열 분석
https://www.acmicpc.net/problem/10820
*/
/*
#include <iostream>
#include <string>
using namespace std;

int main() {
	string str_buf;
	while (getline(cin, str_buf)) {
		int arr[4] = { 0, };	// 소, 대, 숫, 공
		for (int i = 0; i < str_buf.size(); i++) {
			if (str_buf[i] == '\n')
				break;
			if ((65 <= str_buf[i] && 90 >= str_buf[i]))	// 대문자
				arr[1] += 1;
			else if ((97 <= str_buf[i] && 122 >= str_buf[i]))
				arr[0] += 1;
			else if (48 <= str_buf[i] && 57 >= str_buf[i])
				arr[2] += 1;
			else
				arr[3] += 1;
		}
		for (int j = 0; j < 4; j++) {
			printf("%d ", arr[j]);
		}
		printf("\n");

	}
	return 0;
}
*/