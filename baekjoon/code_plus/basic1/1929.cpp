/*
[BOJ] 1929. 소수 구하기
*/
#include <iostream>
#define MAX 1000000
using namespace std;
int main(){
    int m, n;
    cin>>m>>n;
    bool prime[MAX+1];
    prime[1] = true;
    for(int i=2;i*i<=MAX;i++){
        if(!prime[i]){
            for(int j=(i*i); j<=MAX; j+=i){
                prime[j] = true;
            }
        }
    }
    for (int i=m; i<=n; i++) {
        if (!prime[i]) cout<<i<<"\n";
    }

    return 0;
}