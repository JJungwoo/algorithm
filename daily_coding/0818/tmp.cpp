/*
[boj] 
https://www.acmicpc.net/problem/
*/

#include <iostream>
#include <vector>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, k, a, b, c;
vector<pair<int, int> > vp[1001];
priority_queue<pair<int, int> > path[1001];
int main()
{
    io;
    cin>>n>>m>>k;
    for(int i=0;i<m;i++){
        cin>>a>>b>>>c;
        vp[a-1].push_back(make_pair(b-1, c));
    }

    path[0].make_pair(0, 0);
    
    return 0;
}

