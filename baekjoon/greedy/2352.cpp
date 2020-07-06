/*
[boj] 2352. 반도체 설계
https://www.acmicpc.net/problem/2352
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, ans;
vector<int> board, lis;
int main()
{
    io;
    cin>>n;
    board.resize(n+1);
    for(int i=0;i<n;i++)
        cin>>board[i];
    lis.push_back(board[0]);
    for(int i=0;i<n;i++){
        if(lis[ans] <= )
    }
    return 0;
}