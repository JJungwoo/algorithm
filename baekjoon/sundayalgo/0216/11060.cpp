/*
[BOJ] 11060. 점프 점프
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int arr[1001], dp[1001];
int main()
{
    io;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<=n;i++){
        arr[i] = min(arr[i-arr[i]], arr[i]);
        cout<<i<<" : "<<arr[i]<<","<<arr[i-arr[i]]<<"\n";
    }
    cout<<arr[n]<<"\n";
    return 0;
}