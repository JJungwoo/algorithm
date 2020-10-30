/*
[boj] 18258. 큐 2 
https://www.acmicpc.net/problem/18258
*/

#include <iostream>
#include <queue>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N;
int main() 
{
    io;
    cin >> N;
    queue<int> q;
    while(N--) {
        string input; cin >> input;
        if(!input.compare("push")) {
            int value; cin >> value;
            q.push(value);
        }else if(!input.compare("pop")) {
            if(q.empty()) cout<<"-1\n";
            else {
                cout<<q.front()<<"\n";
                q.pop();
            }
        }else if(!input.compare("size")) {
            cout<<q.size()<<"\n";
        }else if(!input.compare("empty")) {
            cout<<q.empty()<<"\n";
        }else if(!input.compare("front")) {
            if(q.empty()) cout<<"-1\n";
            else cout<<q.front()<<"\n";
        }else if(!input.compare("back")) {
            if(q.empty()) cout<<"-1\n";
            else cout<<q.back()<<"\n";
        }
    }   
    return 0;
}