/*
[BOJ] 17404. RGB거리 2
이 문제는 RGB거리1이 있다. 문제 조건은 다 동일한데 이 한문장만 다르다.
집 i의 이웃은 집 i-1과 집 i+1이고, 첫 집과 마지막 집도 이웃이다. 가지가지한다;;;
이 말은 1, 3번째 위치가 이웃이 된다는 말이다. 앞과 뒤가 연결되서 환형 구조가 된다.
먼저 1을 다시 풀어서 기억을 되살려보자.

*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
vector<vector<int> > house;

int main()
{
    io;
    cin>>n;
    house.resize(n + 1, vector<int>(3,0));
 
    for(int i=0;i<n;i++){
        cin>>house[i];
        cout<<i<<":"<<house[i]<<"\n";
    }
    
    return 0;
}