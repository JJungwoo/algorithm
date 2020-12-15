/*
[boj] 2512. 예산 
https://www.acmicpc.net/problem/2512
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
int N, M;
ll nums[10001], el_max;
bool isSuccess(ll mid) {
    ll sum = 0;
    for(int i=0;i<N;i++) {
        if(mid < nums[i]) 
            sum += mid;
        else
            sum += nums[i];
    }
    return (M >= sum);
}
int main() 
{
    io;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> nums[i];
        if(el_max < nums[i]) el_max = nums[i];
    }
    cin >> M;
    ll left = 0, right = el_max;
    while(left <= right) {
        ll mid = (left + right) / 2;
        if(isSuccess(mid)) {
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    cout<<left - 1<<"\n";
    return 0;
}