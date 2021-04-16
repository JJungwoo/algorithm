/*
[boj] 1005. ACM Craft
https://www.acmicpc.net/problem/1005
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define START_POINT 0
#define MAX_INT 1e9
int N, K, W;
int building[1001];
vector<int> dp, way_count;
vector<int> pos[1001];
void all_clear() {
    dp.clear();
    dp.resize(N, -MAX_INT);
    way_count.clear();
    way_count.resize(N, 0);
    for(int i=0;i<N;i++) {
        pos[i].clear();
    }
}
bool go_build(int idx) {
    queue<int> q;
    q.push(idx);

    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == W) {
            return true;
        }
        for(int nxt : pos[cur]) {
            if (--way_count[nxt] == 0) {
                q.push(nxt);
            }
            if (dp[nxt] < dp[cur] + building[nxt]) {
                dp[nxt] = dp[cur] + building[nxt];
            }
        }
    }
    return false;
}
int main() 
{
    io;
    int T;
    cin >> T;
    while(T--) {
        cin >> N >> K;
        
        all_clear();
        for(int i=0;i<N;i++) {
            cin >> building[i];
        }
        for(int i=0;i<K;i++) {
            int X, Y;
            cin >> X >> Y;
            pos[X-1].push_back(Y-1);
            way_count[Y-1]++;
        }
        cin >> W;
        W--;
        // find start point
        for(int i=0;i<N;i++)
            if (way_count[i] == START_POINT && dp[i] == -MAX_INT) {
                dp[i] = building[i];
                if(go_build(i)) break;
            }
        cout << dp[W] << "\n";
    }
    return 0;
}

/*

// dfs 시간초과..

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define START_POINT 0
#define MAX_INT 1e9
int N, K, W;
int building[1001];
vector<int> dp;
vector<int> pos[1001];
void all_clear() {
    dp.clear();
    dp.resize(N, -MAX_INT);
    for(int i=0;i<N;i++) {
        pos[i].clear();
    }
}
bool go_build(int idx) {
    if (idx == W) {
        return true;
    }
    
    for(int next : pos[idx]) {
        if (dp[idx] + building[next] > dp[next]) {
            dp[next] = dp[idx] + building[next];
            go_build(next);
        }
    }
    return false;
}
int main() 
{
    io;
    int T;
    cin >> T;
    while(T--) {
        cin >> N >> K;
        vector<int> way_count(N, 0);
        all_clear();
        for(int i=0;i<N;i++) {
            cin >> building[i];
        }
        for(int i=0;i<K;i++) {
            int X, Y;
            cin >> X >> Y;
            pos[X-1].push_back(Y-1);
            way_count[Y-1]++;
        }
        cin >> W;
        W--;
        // find start point
        for(int i=0;i<N;i++)
            if (way_count[i] == START_POINT && dp[i] == -MAX_INT) {
                dp[i] = building[i];
                if(go_build(i)) break;
            }
        cout << dp[W] << "\n";
    }
    return 0;
}
*/
