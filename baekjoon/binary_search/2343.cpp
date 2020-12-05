/*
[boj] 2343. 기타 레슨 
https://www.acmicpc.net/problem/2343
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int N, M;
int lesson[100001];
bool isSuccess(int stand) {
    int sum = 0, cnt = 0;
    for(int i=0;i<N;i++) {
        if(lesson[i] > stand) 
            return false;
        if(sum + lesson[i] <= stand) {
            sum += lesson[i];
        }else{
            sum = lesson[i];
            cnt++;
        }
    }
    if(sum != 0 && sum <= stand) cnt++;
    return M >= cnt;
}
int main() 
{
    io;
    int sum = 0;
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> lesson[i];
        sum += lesson[i];
    }
    int left = 0, right = sum;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(isSuccess(mid)) {
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    cout<<right + 1<<"\n";   
    return 0;
}