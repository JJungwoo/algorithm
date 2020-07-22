/*
[BOJ] 3015. 오아시스 재결합 
https://www.acmicpc.net/problem/3015
스택을 활용
스택의 탑 위치를 항상 반대편을 바라볼수 있는 기준점으로 생각
기준보다 더 큰 값이 나오면 새로운 기준이 생겼으니 스택에 있는 값 모두 제거
*/

#include <iostream>
#include <stack>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef long long ll;
ll n, input, ans;
stack<pair<ll, ll> > s;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>input;
        pair<ll, ll> p = make_pair(input ,1);
        if(s.empty())
            s.push(p);
        else{
            while(!s.empty() && s.top().first <= input) {
                ans += s.top().second;
                if(s.top().first == input) p.second += s.top().second;
                s.pop();
            }
                         
            if(!s.empty()) ans++;
            s.push(p);
        }
    }
    cout<<ans<<"\n";
    return 0;
}