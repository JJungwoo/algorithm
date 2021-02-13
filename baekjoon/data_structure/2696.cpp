/*
[boj] 2696. 중앙값 구하기
https://www.acmicpc.net/problem/2696
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main() {
    io;
    int T; cin >> T;
    while (T--) {
        priority_queue<int> low, high;  // 오름차순, 내림차순
        int M; cin >> M;
        cout<<ceil((float)M/2)<<"\n";
        for(int i=1;i<=M;i++) {
            int N; cin >> N;
            low.size() == high.size() ? high.push(N) : low.push(-N);
            if(!low.empty() && !high.empty() && (-low.top() < high.top())) {
                int ht = high.top(), lt = -low.top();
                high.pop(), low.pop();
                high.push(lt), low.push(-ht);
            }
            if(i%2 != 0)
                cout<<high.top()<<" ";
        }
        cout<<"\n";
    }
    return 0;
}