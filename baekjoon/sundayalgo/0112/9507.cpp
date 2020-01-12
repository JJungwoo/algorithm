/*
[BOJ] 9507. Generations of Tribbles
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef long long ll;
// 1 + 1 + 2 + 4
int main()
{
    io;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll koong[70] = {0,};
        koong[0] = 1;
        koong[1] = 1;
        koong[2] = 2;
        koong[3] = 4;
        for(int i=4;i<=n;i++){
            koong[i] = koong[i-1] + koong[i-2] + koong[i-3] + koong[i-4];
        }
        cout<<koong[n]<<"\n";
    }

    return 0;
}