/*
[boj] 1806. 부분합 
https://www.acmicpc.net/problem/1806
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define min(a, b) (a < b ? a : b)
const int INF = 987654321;
int N;
long long S, num[100001], answer = INF;
int main() 
{
    io;
    cin >> N >> S;
    for(int i=0;i<N;i++) {
        cin >> num[i];
    }
    int left = 0, right = 0;
    long long sum = 0;
    while(left <= right) {
        if(sum >= S) {
            answer = min(answer, right - left);
            sum -= num[left++];
        }
        else if(right == N) 
            break;
        else 
            sum += num[right++];
    }
    if(answer == INF) answer = 0;
    cout<<answer<<"\n";
    return 0;
}