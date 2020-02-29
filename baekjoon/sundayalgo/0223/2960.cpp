/*
[BOJ] 2960. 에라토스테네스의 체
*/

#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

bool prime[1001];

int get_prime(int end, int cnt)
{
    int get_cnt = 1;
    for(int i=2;i<=end;i++){
        for(int j=i;j<=end;j+=i){
            if(!prime[j]) prime[j] = true;
            else continue;
            //cout<<j<<" ";
            if(get_cnt == cnt){
                return j;
            }
            get_cnt++;
        }
    }
    return 0;
}

int main()
{   
    io;
    int n, k;
    cin>>n>>k;
    cout<<get_prime(n,k)<<"\n";

    return 0;
}