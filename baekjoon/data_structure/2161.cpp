/*
[boj] 2161. 카드1 
https://www.acmicpc.net/problem/2161
*/

#include <iostream>
#include <queue>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
vector<int> answer;
queue<int> s;
int main() 
{
    io;
    cin >> N;
    int cnt = 1;
    for(int i=1;i<=N;i++)
        s.push(i);

    while(s.size() != 1) {
        if(cnt % 2 == 0) {
            int tmp = s.front();
            s.pop();
            s.push(tmp);
        }else {
            answer.push_back(s.front());
            s.pop();
        }
        cnt++;
    }
    for(auto it : answer) {
        cout<<it<<" ";
    }
    cout<<s.front()<<"\n";
    return 0;
}