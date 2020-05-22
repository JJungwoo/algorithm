/*
[boj] 12015. 가장 긴 증가하는 부분 수열 2
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n;
vector<int> a;
int main()
{
    io;
    cin>>n;
    a.resize(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    
    return 0;
}