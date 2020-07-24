/*
[boj] 14864. 줄서기
https://www.acmicpc.net/problem/14864
위상 정렬로 각 학생의 순서를 표현할 수 있다. 
게런데 학생간의 순서를 알 수 없는 경우를 
어떻게 찾을지 모르겠다..
아니다 위상 정렬로 해결하는 방법이 아닌 이미 학생들은 순서대로 정렬된 카드를 갖고 있다.
여기서 주어진 관계를 통해 뒤바뀐 카드를 예측할 수 있다.
http://blog.naver.com/PostView.nhn?blogId=jhc9639&logNo=221764387481&parentCategoryNo=&categoryNo=&viewDate=&isShowPopularPosts=false&from=postView
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,m,x,y;
int student[100001], visited[100001];
int main() 
{
    io;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        student[x]++;
        student[y]--;
    }
    for(int i=1;i<=n;i++){
        student[i] += i;
        visited[student[i]]++;
    }
    bool check = true;
    for(int i=1;i<=n;i++){
        if(visited[i] == 0 || visited[i] >= 2) {
            check = false;
            break;
        }
    }
    if(!check) 
        cout<<"-1\n";
    else {
        for(int i=1;i<=n;i++)
            cout<<student[i]<<" ";
        cout<<"\n";
    }
    return 0;
}

/*
// dfs 위상 정렬 방법..

int n,m,x,y,cnt;
vector<int> graph[100001];
int student[100001];
void dfs(int s){
    
    for(auto it : graph[s]){
        if(student[it]) continue;
        dfs(it);
    }

    student[s] = ++cnt;
}
int main()
{
	io;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        graph[x-1].push_back(y-1);
    }
    for(int i=0;i<n;i++){
        if(student[i]) continue;
        dfs(i);
    }
    if(cnt != n)
        cout<<"-1\n";
    else{
        for(int i=0;i<n;i++)
            cout<<student[i]<<" ";
        cout<<"\n";
    }
	return 0;
}
*/