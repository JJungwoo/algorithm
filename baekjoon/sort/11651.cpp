/*
[boj] 11651. 좌표 정렬하기 2
*/

#include <iostream>
#include <set>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
set <pair<int, int> > s;
int n;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        s.insert(make_pair(b,a));
    }

    for(auto it : s)
        cout<<it.second<<" "<<it.first<<"\n";

    return 0;
}