/*
[BOJ] 2824 최대공약수
http://yukari-ko.blogspot.com/2014/08/2824.html
http://blog.naver.com/PostView.nhn?blogId=programmer18&logNo=221159857893&parentCategoryNo=&categoryNo=286&viewDate=&isShowPopularPosts=false&from=postView


#include <iostream>
#pragma warning(disable:4996)
using namespace std;

typedef unsigned long long LL;

int main()
{
	LL n, m, a = 1, b = 1, value;
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &value);
		a *= value;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%lld", &value);
		b *= value;
	}
	
	return 0;
}
*/
/*
LL gcd(LL a, LL b) {
	return b ? gcd(b, a%b) : a;
}

int main()
{
	LL n, m, a = 1, b = 1, value;
	scanf("%lld",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &value);
		a *= value;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%lld", &value);
		b *= value;
	}
	printf("%lld\n", a > b ? gcd(a,b) : gcd(b,a));
	 
	return 0;
}

*/