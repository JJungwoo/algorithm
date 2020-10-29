/*
[boj] 2250. 트리의 높이와 너비 
https://www.acmicpc.net/problem/2250
10.29 메모리 초과 발생.. 메모리를 최대한 사용하지 않도록 최적화가 필요하다..
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
pair<int, int> mm[11];    // 각 레벨의 너비를 구하기 위한 벡터
vector<int> map[10001];
int N, quadrangle[10001][11], gidx = 1, glevel;
void find_child(int cur, int level) {
    if(map[cur][0] != -1) 
        find_child(map[cur][0], level+1);
    quadrangle[level][gidx] = cur;
    if(mm[level].first == 0 || mm[level].first > gidx)
        mm[level].first = gidx;
    if(mm[level].second == 0 || mm[level].second < gidx)
        mm[level].second = gidx;
    gidx++;
    glevel = max(glevel, level);
    if(map[cur][1] != -1)
        find_child(map[cur][1], level+1);
}
int main() 
{
    io;
    cin >> N;
    int root = 0;
    vector<int> find_parent(N+1, 0);
    for(int i=0;i<N;i++) {
        int A, B, C;
        cin >> A >> B >> C;
        map[A].push_back(B);
        map[A].push_back(C);
        find_parent[B] = find_parent[C] = 1;
    }
    for(int i=1;i<=N;i++) {
        if(find_parent[i] == 0) {
            root = i;
            break;
        }
    }
    find_child(root, 1);
    int maxdiff = 0, answer = 0;
    for(int i=1;i<=glevel;i++) {
        int diff = mm[i].second - mm[i].first + 1;
        if(maxdiff < diff) {
            maxdiff = diff;
            answer = i;
        }
    }
    cout<<answer<<" "<<maxdiff<<"\n";
    return 0;
}