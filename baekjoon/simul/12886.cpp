/*
[BOJ] 12886. 돌 그룹
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int ans;
int group[3], tmp[2];
bool visited[3];

bool check_end()
{
    return (group[0] == group[1]) && (group[0] == group[2]);
}

void active()
{
    
}

void solve(int cnt)
{
    if(cnt == 2){
        queue<pair<int, int> > qp;
        qp.push(make_pair(tmp[0], tmp[1]));
        while(!qp.empty()){
            int x = qp.front().first > qp.front().second ? qp.front().first : qp.front().second; 
            int y = qp.front().first < qp.front().second ? qp.front().first : qp.front().second;  
            qp.pop();
            
            if(check_end()){
                ans = 1;
            }
            for(int i=0;i<3;i++){

            }
        }
    }
    

    for(int i=0;i<3;i++){
        if(visited[i]) continue;
        visited[i] = true;
        tmp[cnt] = i;
        solve(cnt+1);
        visited[i] = false;
    }
}

int main()
{
    io;
    for(int i=0;i<3;i++){
        cin>>group[i];
    }
    solve(0);
    cout<<ans<<"\n";
    return 0;
}