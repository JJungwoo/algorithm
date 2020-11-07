/*
[boj] 2559. 수열 
https://www.acmicpc.net/problem/2559
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, K, map[100001], ans;
int main() 
{
    io;
    cin >> N >> K;
    for(int i=0;i<N;i++) {
        cin >> map[i];
        ans = max(ans, map[i]);
    }
    if(K == 1) {
        cout<<ans<<"\n";
        return 0;
    }
    int sum = 0, left = 0, right = K-1;
    for(int i=0;i<K;i++) {
        sum += map[i];
    }
    ans = sum;
    while(left <= right) {
        if(right == N-1) break;
        sum -= map[left];
        left++;
        right++;
        sum += map[right];
        ans = max(ans, sum);
    }
    cout<<ans<<"\n";
    return 0;
}