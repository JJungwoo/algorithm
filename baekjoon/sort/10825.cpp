/*
[boj] 10825. 국영수
*/

#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n;
tuple<string, int, int, int> v[100000];
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        string msg;
        int a,b,c;
        cin>>msg>>a>>b>>c;
        v[i] = tie(msg, a, b, c);
    }
    sort(v, v + n, [](tuple<string, int, int, int> &a, tuple<string, int, int, int> &b){
        if(get<1>(a) != get<1>(b)) return get<1>(a) > get<1>(b);
        else if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
        else if(get<3>(a) != get<3>(b)) return get<3>(a) > get<3>(b);
        return get<0>(a) < get<0>(b);
    });
    for(int i=0;i<n;i++)
        cout<<get<0>(v[i])<<"\n";
    
    return 0;
}