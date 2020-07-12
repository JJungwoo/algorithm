/*
[boj] 17608. 막대기
https://www.acmicpc.net/problem/17608
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, max_value, ans;
vector<int> v, lis;
int main()
{
	io;
    cin>>n;
    v.resize(n+1);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=n-1;i>=0;i--){
        if(max_value < v[i]){
            max_value = v[i];
            ans++;
        }
    }
    cout<<ans<<"\n";
}