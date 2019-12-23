/*
sphere online judge. give away
sqrt decomposition
https://www.spoj.com/problems/GIVEAWAY/
ref: https://github.com/krnbatra/SPOJ-Solutions/blob/master/GIVEAWAY.cpp
*/
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, q, sqc_idx;
vector<int> arr;
vector<int> sqc;
void init(){
    sqc_idx = sqrt(n);
    for(int i=0;i<n;i++){
        sqc[i/sqc_idx].push_back(arr[i]);
    }
}
void update(int idx, int value){
    int diff = arr[idx] - value;
    arr[idx] = value;
    sqc[idx/sqc_idx] += diff;
}
ll qsearch(int l, int r, ll stand){
    int find = 0;
    while(l<=r){
        int max = (l+r)/2;
        if(){

        }else {

        }
    }
}
int main()
{
    scanf("%lld", &n);
    arr.resize(n+1);
    sqc.resize(n+1);
    for(int i=0;i<n;i++) scanf("%lld", &arr[i]);
    init();
    int sqc_blocks = ceil((double)n/sqc_idx);
    for(int i=0;i<sqc_blocks;i++)
        sort(sqc[i].begin(), sqc[i].end());
    scanf("%d", &q);
    for(int i=0;i<q;i++){
        int inputC;
        scanf("%d", &inputC);
        if(inputC){     // update
            ll a,b;
            scanf("%lld %lld", &a, &b);
            update(a, b);
        }else {
            ll a,b,c;
            scanf("%lld %lld %lld", &a, &b, &c);

        }
    }

    return 0;
}
