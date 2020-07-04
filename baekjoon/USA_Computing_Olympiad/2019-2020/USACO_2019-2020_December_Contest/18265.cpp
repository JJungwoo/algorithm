/*
[boj] 18265. MooBuzz
https://www.acmicpc.net/problem/18265
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
// 3 6 9 12 15 18 21 24 27 30 
// 33 36 39 42 45 48 51 54 57 60

// 5 10 15 20 25 30
// 35 40 45 50 55 60

// 15 30
// 45 60
typedef long long ll;
ll n;
int main()
{
	io;
    cin>>n;
    ll left = 0, right = 5 * n;
    while(left < right){
        ll mid = (left + right) / 2;
		ll answer = mid - (mid/3) - (mid/5) + (mid/15);
        if(answer >= n)
            right = mid;
        else 
            left = mid + 1;
    }
    cout<<left<<"\n"; 
    return 0;
}
