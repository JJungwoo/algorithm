/*
[boj] 12851. 숨바꼭질 2 
https://www.acmicpc.net/problem/12851
*/

#include <iostream>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAXVAL 1000000
const int dir[3] = {-1, 1, 2};
int N, K, answer;
int visited[MAXVAL+1];
struct obj {
    int pos, cnt;
    obj(int _pos, int _cnt) : pos(_pos), cnt(_cnt) {}
};
void bfs(int start) {
    queue<obj> q;
    q.push(obj(start, 0));
    while(!q.empty()) {
        int cur = q.front().pos, cnt = q.front().cnt;
        q.pop();
        if(cur == K) {
            answer++;
            continue;
        }
        for(int i=0;i<3;i++) {
            int mpos;
            if(i <= 1) mpos = cur + dir[i];
            else mpos = cur * dir[i]; 
            if(mpos < 0 || mpos > MAXVAL) continue;
            if(visited[mpos] == 0 || visited[mpos] >= cnt + 1) {
                visited[mpos] = cnt + 1;
                q.push(obj(mpos, cnt+1));
            }            
        }
    }
}
int main() 
{
    io;
    cin >> N >> K;
    if(N == K) {
        cout<<"0\n"<<"1\n";
        return 0;
    }
    bfs(N);
    cout<<visited[K]<<"\n";
    cout<<answer<<"\n";
    return 0;
}