/*
[BOJ] 2225. 합분해
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, k;
int dp[201];

int main()
{
    io;
    cin>>n>>k;
    for(int i=0;i<=n;i++)dp[i] = i;


    return 0;
}