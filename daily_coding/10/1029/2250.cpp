/*
[boj] 2250. 트리의 높이와 너비 
https://www.acmicpc.net/problem/2250
10.29 메모리 초과 발생.. 메모리를 최대한 사용하지 않도록 최적화가 필요하다..
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
const int INF = 987654321;
pair<int, int> map[10001];
int N, gidx = 1;
int low[10001], high[10001], find_parent[10001];
void find_child(int cur, int level) {
    if(map[cur].first > 0) 
        find_child(map[cur].first, level+1);
    low[level] = min(low[level], gidx);
    high[level] = max(high[level], gidx);
    gidx++;
    if(map[cur].second > 0)
        find_child(map[cur].second, level+1);
}
int main() 
{
    io;
    cin >> N;
    int root = 0;
    for(int i=1;i<=N;i++) {
        int A, B, C;
        cin >> A >> B >> C;
        map[A].first = B, map[A].second = C;
        find_parent[B] = find_parent[C] = 1;
        low[i] = INF;
    }
    for(int i=1;i<=N;i++) {
        if(find_parent[i] == 0) {
            root = i;
            break;
        }
    }
    find_child(root, 1);
    int maxdiff = 0, answer = 0;
    for(int i=1;i<=N;i++) {
        int diff = high[i] - low[i] + 1;
        if(maxdiff < diff) {
            maxdiff = diff;
            answer = i;
        }
    }
    cout<<answer<<" "<<maxdiff<<"\n";
    return 0;
}