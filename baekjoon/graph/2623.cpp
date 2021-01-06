/*
[boj] 2623. 음악프로그램 
https://www.acmicpc.net/problem/2623
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M;
int refcnt[1001];
vector<int> singer[1001], ans;
void find_seq(int idx) {
    if(refcnt[idx] == 0) {
        refcnt[idx] = -1;
        ans.push_back(idx);
    }else return;

    for(auto nxt : singer[idx]) {
        if(refcnt[nxt] != 0) {
            refcnt[nxt]--;
            find_seq(nxt);
        }
    }
}
int main()
{
    io;
    cin >> N >> M;
    for(int i=0;i<M;i++) {
        int cnt; cin >> cnt;
        int first = 0;
        for(int j=0;j<cnt;j++) {
            int second; cin >> second;
            if(first != 0) {
                singer[first].push_back(second);
                refcnt[second]++;
            }
            first = second;
        }
    }
    for(int i=1;i<=N;i++)
        if(refcnt[i] == 0)
            find_seq(i);
    if(ans.size() != N) {
        cout << "0\n";
        return 0;
    }
    for(auto nxt : ans) {
        cout<<nxt<<"\n";
    }
    return 0;
}