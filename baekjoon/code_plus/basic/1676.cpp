/*
[BOJ] 1676. 팩토리얼 0의 개수
*/
#include <iostream>
using namespace std;
int main()
{
	int n, ans = 0;
	cin>>n;
  	while (n) n /= 5, ans += n;
    cout<<ans;
	return 0;
}