/*
[BOJ] 2004. 조합 0의 개수
nCm = n! / m!*(n-m)!
왜 2와 5의 배수 개수를 구한다음 최소 값을 해줘야 할까?.. 
당연히 5의 배수 값이 훨씬 적지 않을까? 이에 대한 반론 예시가 필요하다..
ref: https://jaimemin.tistory.com/908
*/
#include <cstdio>
#include <algorithm>
using namespace std;
long long zero_cal(long long num, long long div)
{
    long long sum = 0;
    while(num) {
        num /= div;
        sum += num;
    }
    return sum;
}
int main()
{
    long long n,m;
    scanf("%lld %lld", &n, &m);
    printf("%lld\n", min(zero_cal(n,2) - zero_cal(m,2) - zero_cal(n-m,2), 
    zero_cal(n,5) - zero_cal(m,5) - zero_cal(n-m,5)));
    return 0;
}