/*
[BOJ] 10819. 차이를 최대로 
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, ans;
int seq[8];

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++) cin>>seq[i];
    sort(seq, seq + n);
    do{
        int sum = 0;
        for(int i=0;i<n-1;i++){
            sum += abs(seq[i]-seq[i+1]);
        }
        if(ans < sum) ans = sum;
    }while(next_permutation(seq, seq + n));
    cout<<ans<<"\n";
    return 0;
}