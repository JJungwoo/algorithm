/*
[boj] 2217. 로프 
https://www.acmicpc.net/problem/2217
*/

#include <iostream>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, ans;
int main()
{
    io;
    cin>>N;
    int arr[N];

    for (int i = 0; i < N; i++) cin>>arr[i];
    sort(arr, arr+N);
    for (int i = 0; i < N; i++) ans = max(ans, arr[i]*(N-i));
    cout<<ans<<"\n";
    return 0;
}