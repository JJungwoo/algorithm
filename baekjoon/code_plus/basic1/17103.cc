/*
[BOJ] 17103. 골드바흐 파티션
*/
#include <cstdio>
using namespace std;
const int max = 1e6;
bool prime[max+1];
void prime_check(){
    prime[1] = true;
    for(int i=2;i*i<=max;i++){
        if(!prime[i]){
            for(int j=i*i;j<=max;j+=i){
                prime[j] = true;
            }
        }
    }
}
int main()
{
    int t, n;
    scanf("%d", &t);
    prime_check();
    while(t--){
        int ans = 0;
        scanf("%d", &n);
        if(!prime[n]) ans++;
        for(int i=2;i<=n/2;i++){
            printf("%d %d %d\n", prime[n-i], n-i, ans);
            if(!prime[i] && !prime[n - i]){
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}