/*
[boj] 15684. 사다리 조작
https://www.acmicpc.net/problem/15684
*/

/*
N : 세로
M : 세로 사이 막대기
H : 가로 
정말 더러운 문제... 
1) 일단 시간초과를 해결하기 위해서 인덱스 저장 필수 --> 시간초과
2) 그리고 좌표 양 옆 체크하고 가로선 긋기 --> 9%
3) 마지막으로 저장한 인덱스 함수로 넘길때 +1하면 틀림 인덱스 그대로 넘겨야 통과..; --> 70%
*/
#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M, H, answer = 4;
bool map[31][31], visited[31][31];
void solve(int idx, int cnt) {
    if(cnt > 3) return;
    if(cnt <= 3) {
        bool end = true;
        for(int i=0;i<N;i++) {
            int idx = i;
            for(int j=0;j<H;j++) {
                if(idx + 1 < N && map[j][idx]) {
                    idx += 1;
                }else if(idx - 1 >= 0 && map[j][idx - 1]) {
                    idx -= 1;
                }
            }
            if(idx != i) {
                end = false;
                break;
            }
        }
        if(answer > cnt && end == true) {
            answer = cnt;
            return;
        }
    }
    
    for(int i=idx;i<H;i++) {
        for(int j=0;j<N;j++) {
            if(map[i][j]) continue;
            if(j-1 >= 0 && (map[i][j-1] || map[i][j+1])) continue;
            map[i][j] = true;
            solve(i, cnt + 1);
            map[i][j] = false;
        }
    }
}
int main() 
{
    io;
    cin >> N >> M >> H;
    for(int i=0;i<M;i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        if(B == N-1) B--;
        map[A][B] = true;
    }

    solve(0, 0);
    if(answer > 3) answer = -1;
    cout<<answer<<"\n";
    return 0;
}