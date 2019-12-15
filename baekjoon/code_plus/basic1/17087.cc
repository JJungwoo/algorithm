/*
[BOJ] 17087. 숨바꼭질 6
*/
#include <cstdio>
using namespace std;
const int max = 1e5;
long long arr[max+1];
long long gcd(long long a, long long b)
{
    if(b == 0) return a;
    else return gcd(b, a%b);
}
int main()
{
    long long n, s;
    scanf("%lld %lld", &n, &s);
    for(int i=0;i<n;i++){
        long long tmp;
        scanf("%lld", &tmp);
        tmp -= s;
        arr[i] = (tmp < 0 ? tmp * -1: tmp);
    }
    long long ans = arr[0];
    for(int i=1;i<n;i++){
        ans = gcd(ans, arr[i]);
    }
    printf("%lld\n", ans);
    
    return 0;
}