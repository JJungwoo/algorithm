/*
[boj] 12015. 가장 긴 증가하는 부분 수열 3
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n;
vector<int> a, lis;
int main()
{
    io;
    cin>>n;
    a.resize(n+1,0);
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(i == 0) lis.push_back(a[i]);
        else if(lis.back() < a[i]) lis.push_back(a[i]);
        else {
            int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            cout<<idx<<"\n";
            lis[idx] = a[i];
        }
    }
    cout<<lis.size()<<"\n";
    return 0;
}