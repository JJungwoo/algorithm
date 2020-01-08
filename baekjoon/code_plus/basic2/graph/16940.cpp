/*
[BOJ] 16940. BFS 스페셜 저지
*/
#include <iostream>
#include <queue>
#include <cstring>
#include <unordered_set>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MAX = 1e6;
int n;
vector<int> seq[MAX+1];
unordered_set<int> tree[MAX+1];    // 부모, 나
int ans[MAX+1];
bool visited[MAX+1];
int idx = 1;

void bfs(){
    queue<int> q;
    visited[1] = true;
    q.push(1);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        unordered_set<int> us;
        for(int next : seq[x]){
            if(visited[next]) continue;
            visited[next] = true;
            us.insert(next);
        }
        for(int i=idx;i<idx+us.size();i++){
            if(us.count(ans[i]) == 0){
                cout<<"0\n";
                return ;
            } else q.push(ans[i]);
        }
        idx += us.size();
    }
    cout<<"1\n";
}

int main()
{
    io;
    cin>>n;
    for(int i=1;i<n;i++){
        int x, y; cin>>x>>y;
        seq[x].push_back(y);
        seq[y].push_back(x);
    }
    for(int i=0;i<n;i++) cin>>ans[i];
    if(ans[0] != 1){
        cout<<"0\n";
        return 0;
    }
    bfs();
    /*
    for(int cnt=0,i=0;cnt<n;cnt++){
        bool find = false;
        while(tree[cnt].find(ans[i]) != tree[cnt].end()){
            i++;
            if(i > n){
                cout<<i<<"\n";
                return 0;
            }
        }
        if(find == false){
            cout<<"0\n";
            return 0;
        }
    }
    */    
    
    return 0;
}