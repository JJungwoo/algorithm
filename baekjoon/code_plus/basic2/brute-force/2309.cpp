/*
[BOJ] 2309. 일곱 난쟁이
dfs로도 풀수 있을 것 같은데..
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int a[9], sum;

void solve(){
    sort(a, a+9);
    for(int i=0;i<9;i++){
        for(int j=0;j<i;j++){
            if(sum - (a[i] + a[j]) == 100){
                for(int z=0;z<9;z++){
                    if(z != i && z != j)
                        cout<<a[z]<<"\n";
                }
                return;
            }
        }
    }
}

int main()
{
    io;
    for(int i=0;i<9;i++){
        cin>>a[i];
        sum += a[i];
    }
    solve();
    return 0;
}