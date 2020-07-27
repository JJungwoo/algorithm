/*
[boj] 1461. 도서관
https://www.acmicpc.net/problem/1461
*/


#include <iostream>
#include <algorithm>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,m,ans;
vector<int> load;
int main() 
{
    io;
    cin>>n>>m;
    load.resize(n);
    for(int i=0;i<n;i++){
        cin>>load[i];
    }
    sort(load.begin(), load.end());
    for(auto it : load){
        cout<<it<<" ";
    }

    return 0;
}
