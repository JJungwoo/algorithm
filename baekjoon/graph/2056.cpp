/*
[boj] 2056. 작업
https://www.acmicpc.net/problem/2056
*/

#include<iostream>
#include<vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, complete_time[10001];
int worktime[10001], refcnt[10001];
vector<int> work[10001];
void working(int idx) {
    for(auto nxt : work[idx]) {
        refcnt[nxt]--;
        complete_time[nxt] = max(complete_time[nxt], complete_time[idx] + worktime[nxt]);
        if(refcnt[nxt] == 0) {
            refcnt[nxt] = -1;
            working(nxt);
        }
    }
}
int main() {
    io;
    cin >> N;
    for(int i=1;i<=N;i++) {
        int wt; cin >> wt;
        worktime[i] = wt;
        int num; cin >> num;
        while(num--) {
            int first; cin >> first;
            work[first].push_back(i);
            refcnt[i]++;
        }
    }
    for(int i=1;i<=N;i++)
        if(refcnt[i] == 0) {
            complete_time[i] = worktime[i];
            working(i);
        }
    int ans = 0; 
    for(int i=1;i<=N;i++) {
        ans = max(ans, complete_time[i]);
    }
    cout<<ans<<"\n";
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, ans;
int wtime[10000], d[10000];
vector<int> seq[10000];
int visited[10000];
queue<int> q;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        int work;
        cin>>wtime[i]>>work;
        for(int j=0;j<work;j++){
            int tmp; cin>>tmp;
            tmp--;
            seq[tmp].push_back(i);
            visited[i]++;
        }
    }
    for(int i=0;i<n;i++){
        if(visited[i]) continue;
        q.push(i);
        d[i] = wtime[i];
    }
    while(!q.empty()){
        int here = q.front();
        q.pop();
        for(auto it : seq[here]){
            
            d[it] = max(d[it], d[here] + wtime[it]);
            if(--visited[it] == 0){
                q.push(it);
            }
            //cout<<it<<" : "<<wtime[it]<<" = "<<sum<<"\n";
        }
    
    }

    for(int i=0;i<n;i++){
        //cout<<d[i]<<"\n";
        ans = max(ans, d[i]);
    }
    cout<<ans<<"\n";
    
    return 0;
}

*/