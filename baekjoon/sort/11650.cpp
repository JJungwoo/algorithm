/*
[boj] 11650. 좌표 정렬하기
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
        s.insert(make_pair(a,b));
    }

    for(auto it : s)
        cout<<it.first<<" "<<it.second<<"\n";

    return 0;
}