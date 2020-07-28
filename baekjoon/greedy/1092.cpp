/*
[boj] 1092. 배
https://www.acmicpc.net/problem/1092
커서를 사용하여 뒤에서부터 접근
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n,m,ans;
vector<int> crane, box, cursor;
bool visited[10001];
int main() 
{
    io;
    cin>>n;
    crane.resize(n);
    for(int i=0;i<n;i++)
        cin>>crane[i];
    cin>>m;
    box.resize(m);
    for(int i=0;i<m;i++)
        cin>>box[i];
    
    if(crane.empty()) {
        cout<<"-1\n";
        return 0;
    }

    sort(crane.begin(), crane.end(), greater<int>());
    sort(box.begin(), box.end(), greater<int>());

    if(crane.front() < box.front()) {
        cout<<"-1\n";
        return 0; 
    }

    for(int i=0;i<crane.size();i++)
        cursor.push_back((box.size() <= i ? box.size() : i)); 
    
    int cnt = 0;
    while(cnt < box.size()){
        bool change = false;
        for(int i=0;i<crane.size();i++){
            while(cursor[i] < box.size()){
                if(!visited[cursor[i]] && box[cursor[i]] <= crane[i]) break;
                cursor[i]++;
            }
            if(cursor[i] == box.size()) continue;
            visited[cursor[i]] = true;
            cnt++;
            change = true;
        }
        if(change)
            ans++;
        else {
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<ans<<"\n";

    return 0;
}
