/*
[boj] 14719. 빗물
https://www.acmicpc.net/problem/14719
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int H, W, space[501], ans;
int find_max(int idx, char dir) {
    int ret = 0;
    if(dir == 'L') {
        for(int i=idx;i>=0;i--)
            ret = max(ret, space[i]);
    } else {
        for(int i=idx;i<W;i++)
            ret = max(ret, space[i]);
    }
    return ret;
}
int main()
{
    io;
    cin >> H >> W;
    for(int i=0;i<W;i++) {
        cin >> space[i];
    }
    for(int i=0;i<W;i++) {
        int lmax = find_max(i, 'L');
        int rmax = find_max(i, 'R');
        int diff = min(lmax, rmax);
        ans += diff - space[i];
    }
    cout<<ans<<"\n";
    return 0;
}