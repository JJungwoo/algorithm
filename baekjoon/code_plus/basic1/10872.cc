/*
[BOJ] 10872. 팩토리얼
*/
#include <cstdio>
using namespace std;
int main()
{
    int n, ans = 1;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        ans *= i;
    }
    printf("%d\n", ans);
    return 0;
}