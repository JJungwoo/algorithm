/*
[BOJ] 1107. 리모컨
주어진 n 채널로 이동하기 위해 자리수와 각 자리수에 위치한 값을 최대한 비슷하게 할당해준다.
중간에 기저 조건으로 고장난 버튼은 넘어가준다.
조건은 주어지고 거기서 최적의 해를 구하는 거고.. 노드? 그래프를 사용할 수 없으니.. 
백트래킹이다..
조건을 다시한번 나열해보자
1. 리모컨 버튼(주어진 n값으로 가까운 자리수와 각 위치 숫자 배치)
2. + 연산
3. - 연산
가장 최소값 출력.
먼저 가장 뒷 자리수부터 최소 버튼 값을 구한다음.
맨앞 버튼까지 찾아가자, 주의사항으로 자리수가 고장난 버튼일 경우
가장 가까운 값을 찾고 그전 자리수의 최대값 
ex) 67을 찾는데 6이 고장이면 일단 7버튼 누르고 (1cnt)
70에서부터 - 연산 카운팅을 해준다.
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int cn, n[500001];
int cm, m[11];
int ans

void solve()
{


}

int main()
{
    io;
    cin>>cn;
    cin>>cm;
    for(int i=0;i<cm;i++) cin>>m[i];

    solve();

    cout<<ans<<"\n";

    return 0;
}