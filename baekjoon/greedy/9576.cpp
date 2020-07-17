/*
[boj] 9576. 책 나눠주기
https://www.acmicpc.net/problem/9576
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int t,n,m,a,b,ans;
vector<pair<int, int> > v;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}
bool visited[1001];
int main()
{
    io;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ans = 0;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        fill(visited, visited+n, false);
        sort(v.begin(), v.end(), cmp);
        for(auto it : v){
            for(int i=it.first;i<=it.second;i++){
                if(visited[i]) continue;
                visited[i] = true;
                ans++;
                break;
            }
        }
        cout<<ans<<"\n";
        v.clear();
    }
    return 0;
}

/*
// 뒤에서부터 정렬하면 틀림.. 왜??

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int t,n,m,a,b,ans;
vector<pair<int, int> > v;
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.second == b.second) return a.first > b.first;
    else return a.second > b.second;
}
bool visited[1001];
int main()
{
    io;
    cin>>t;
    while(t--){
        cin>>n>>m;
        ans = 0;
        for(int i=0;i<m;i++){
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }
        fill(visited, visited+n, false);
        sort(v.begin(), v.end(), cmp);
        for(auto it : v){
            //cout<<it.first<<","<<it.second<<"\n";
            if(visited[it.second]){
                int idx = it.second;
                while(idx >= it.first && idx > 0){
                    if(!visited[idx]) {
                        visited[idx] = true;                
                        ans++;
                        break;
                    }
                    idx--;
                }
            }else{
                visited[it.second] = true;
                ans++;
            }
            if(ans == n) break;
        }
        cout<<ans<<"\n";
        v.clear();
    }
    return 0;
}
*/