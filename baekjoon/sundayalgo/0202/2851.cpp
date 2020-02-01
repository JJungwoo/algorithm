/*
[BOJ] 2851. 슈퍼 마리오
*/

#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    io;
    int a[10], tmp = 0;
    int hash[1001] = {0,};
    for (size_t i = 0; i < 10; i++)
    {
        cin>>a[i];
        tmp += a[i];
        hash[tmp] = 1;
    }
    int l = 100,r = 100;
    while(1){
        if(hash[l] || hash[r]){
            break;
        }
        l--;
        r++;
    }
    cout<<(hash[r] ? r : l)<<"\n";
    return 0;
}