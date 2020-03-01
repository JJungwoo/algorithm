/*
[BOJ] 8979. 올림픽
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, k;

struct country{
    int num, g, s, c;
};

bool cmp(const country &c1, const country &c2){
    return make_tuple(-c1.g, -c1.s, -c1.c, c1.num) < make_tuple(-c2.g, -c2.s, -c2.c, c2.num);
}

int main()
{
    io;
    cin>>n>>k;
    vector<country> vc(n);
    for(int i=0;i<n;i++){
        cin>>vc[i].num>>vc[i].g>>vc[i].s>>vc[i].c;
    }

    sort(vc.begin(), vc.end(), cmp);

    for(int i=0;i<n;i++){
        cout<<vc[i].num<<","<<vc[i].g<<","<<vc[i].s<<","<<vc[i].c<<"\n";
    }
    return 0;
}