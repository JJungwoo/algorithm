/*
[boj] 20055. 컨베이어 벨트 위의 로봇
https://www.acmicpc.net/problem/20055
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define START_POINT 1
int N, K;
int conveyer[201];
bool overbelt[101];
void move_conveyer() {
    for (int i=N-1;i>0;i--) {
        if (overbelt[i]) {
            swap(overbelt[i+1], overbelt[i]);
        }
    }
    overbelt[N] = false;

    int dump = conveyer[2*N];
    for (int i=2*N;i>START_POINT;i--) {
        conveyer[i] = conveyer[i-1];
    }
    conveyer[START_POINT] = dump;
}
void move_robot() {
    for (int i=N-1;i>0;i--) {
        if (overbelt[i] && !overbelt[i+1] && conveyer[i+1] > 0) {
            swap(overbelt[i+1], overbelt[i]);
            conveyer[i+1]--;
        }
    }
    overbelt[N] = false;
}
int check_zero() {
    int ret = 0;
    for (int i=1;i<=2*N;i++) {
        if (conveyer[i] == 0) 
            ret++;
    }
    return ret;
}
int main() 
{
    io;
    cin >> N >> K;
    for (int i=1;i<=N*2;i++) {
        cin >> conveyer[i];
    }

    int loop = 1;
    while(1) {
        move_conveyer();
        move_robot();
        if (!overbelt[START_POINT] && conveyer[START_POINT] > 0) {
            overbelt[START_POINT] = true;
            conveyer[START_POINT]--;
        }
        if (check_zero() >= K)
            break;
        loop++;
    }
    cout<<loop<<"\n";
    return 0;
}