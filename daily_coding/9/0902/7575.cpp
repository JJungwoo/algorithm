/*
[boj] 7575. 바이러스 
https://www.acmicpc.net/problem/7575
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
vector<int> program[101];
int main() 
{
    io;
    int N, K;
    cin >> N >> K;
    for(int i=0;i<;N;i++) {
        int M;
        cin >> M;
        program[i].resize(M);
        for(int j=0;j<M;j++) {
            cin >> program[i][j];
        }
    }
    
    
    return 0;
}

