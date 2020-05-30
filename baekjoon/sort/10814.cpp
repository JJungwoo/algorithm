/*
[boj] 10814. 나이순 정렬
*/

#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n;
tuple<int, string, int> v[100000];
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        int num;
        string msg;
        cin>>num>>msg;
        v[i] = tie(num, msg, i);
    }
    sort(v, v + n, [](tuple<int, string, int> &a, tuple<int, string, int> &b){
        if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b);
        else return get<2>(a) < get<2>(b);
    });
    for(int i=0;i<n;i++)
        cout<<get<0>(v[i])<<" "<<get<1>(v[i])<<"\n";
    
    return 0;
}