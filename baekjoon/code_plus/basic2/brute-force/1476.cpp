/*
[BOJ] 1476. 날짜 계산
3 -> 0<지구<16, 0<태양<29, 0<달<20
E, S, M
1 year = 1, 1, 1
ex) 
15Y = 15, 15, 15 
16Y = 1, 16, 16
최소 공배수 구하기? 모든 값이 0으로 떨어질 때가 답
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    io;
    int e, s, m;
    cin>>e>>s>>m;
    int ans = 0;
    while(true){
        int a = ans%15, b = ans%28, c = ans%19;
        cout<<a<<":"<<e-1<<","<<b<<":"<<s-1<<","<<c<<":"<<m-1<<"\n";
        if (a == e-1 && b == s-1 && c == m-1) break;
        ans++;
    }
    cout<<ans + 1<<"\n";
    return  0;
}