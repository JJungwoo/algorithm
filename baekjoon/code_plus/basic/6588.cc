/*
[BOJ] 6588. 골드바흐의 추측
*/
#include <cstdio>
using namespace std;
const int max = 1000000;
bool prime[max+1];
void prime_check(){
    prime[1] = true;
    for(int i=2;i*i<=max;i++){
        if(!prime[i]){
            for(int j=(i*i); j<=max; j+=i){
                prime[j] = true;
            }
        }
    }
}
int main()
{
    int n;
    prime_check();
    while(scanf("%d",&n)){
        int sum = 0, a, b;
        if(n == 0)break;
        for(int i=1;i<=n;i++){
            if(!prime[i]){
                sum = i;
                a = i;
                if(!prime[n - sum]){
                    b = n - sum;
                }
            }
            if(a+b==n) break;
        }
        printf("%d = %d + %d\n", n, a, b);
    }
    return 0;
}