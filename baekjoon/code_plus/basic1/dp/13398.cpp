/*
[BOJ] 13398. 연속합 2
*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int seq[100001];
int dp[100001];

int main()
{
    io;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>seq[i];

    return 0;
}