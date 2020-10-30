/*
[boj] 1967. 트리의 지름
https://www.acmicpc.net/problem/1967
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, answer;
vector<pair<int, int> > vp[10001];
int dfs(int idx) {
    int ret = 0, fst = 0, snd = 0;
    for(auto it : vp[idx]) {
        ret = dfs(it.first) + it.second;
        if(ret > fst) {
            snd = fst;
            fst = ret;
        }else if(ret > snd) {
            snd = ret;
        }
    }
    if(answer < fst + snd) {
        answer = fst + snd;
    }
    return fst;
}
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<N-1;i++) {
        int A, B, C;
        cin >> A >> B >> C;
        vp[A].push_back(make_pair(B, C));
    }
    dfs(1);
    cout<<answer<<"\n";
    return 0;
}