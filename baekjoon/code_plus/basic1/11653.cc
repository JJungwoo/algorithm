/*
[BOJ] 11653. 소인수분해
*/
#include <cstdio>
using namespace std;
const int max = 1e7;
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
int main(){
    int n, tmp = 2;
    scanf("%d", &n);
    prime_check();
    while(1){
        if(!prime[tmp] && n%tmp == 0){
            n /= tmp;
            printf("%d\n", tmp);
        }else if(tmp > n) break; 
        else tmp++;
    }
    return 0;
}