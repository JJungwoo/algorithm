/*
[boj] 3079. 입국심사
https://www.acmicpc.net/problem/3079
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAX_LONGLONG 987654321987654LL;
typedef long long ll;
ll N, M, answer;
vector<ll> check_room;
bool check(ll mid) {
    ll cnt = 0;
    for(ll i : check_room) {
        cnt += mid / i;
    }
    return cnt >= M;
}
int main() 
{
    io;
    cin >> N >> M;
    check_room.resize(N);
    ll max_val = 0;
    for(int i=0;i<N;i++) {
        cin >> check_room[i];
        max_val = max(max_val, check_room[i]);
    }
    answer = max_val * M;
    ll left = 0, right = max_val * M;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (check(mid)) {
            answer = min(answer, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout<<answer<<"\n";

    return 0;
}
