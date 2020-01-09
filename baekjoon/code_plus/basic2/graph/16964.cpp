/*
[BOJ] 16964. DFS 스페셜 저지
뭔 문제인가 싶다.. 똑같이 구현하고 출력 결과만 제대로 나오는지 확인하는건가? 일단 DFS를 구현한다.
https://joonas.tistory.com/94
https://www.acmicpc.net/board/view/34455
방문체크를 반복문 시작 할때마다 체크를 해줬는데, 그러면 안되는 거 였다. 
반복문 시작마다 체크를 해주면 dfs 순서가 첫번째에서 다음 인덱스만 접근되기 때문에 
재귀로 접근했을 때만 체크를 해준다. 그러면 자신이 이전에 접근한 인덱스만 접근안하기 때문에 모든 경우를
체크할 수 있다.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

const int MAX = 1e5;
int n,idx = 1,ans;
vector<int> v[MAX+1];
bool visited[MAX+1];
int check[MAX+1];
int parent[MAX+1];
bool chk_seq[MAX+1];

void dfs(int x){
    if(visited[x]) return;
    visited[x] = true;
    for(int next : v[x]){
        if(!parent[next])
            parent[next] = x;
        dfs(next);
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=0;i<n;i++) cin>>check[i];
    if(check[0] != 1) return cout<<"0\n", 0;
    dfs(1);
    stack<int> stk;
    stk.push(1);
    chk_seq[1] = true;
    while(!stk.empty()){
        bool isDFS = false;
        int x = stk.top();
        for(int next : v[x]){
            //cout<<chk_seq[next]<<"next:"<<next<<"idx:"<<idx<<"!!"<<check[idx]<<":"<<parent[next]<<"\n";
            if(!chk_seq[next] && parent[check[idx]] == x && check[idx] == next){
                stk.push(next);
                chk_seq[next] = true;
                idx++;
                isDFS = true;
                break;
            }
            
        }
        if(!isDFS){
            stk.pop();
        }
    }
    if(idx == n) cout<<"1\n";
    else cout<<"0\n";
    return 0;
}