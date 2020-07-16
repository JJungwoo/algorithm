/*
[boj] 17609. 회문
https://www.acmicpc.net/problem/17609
왜 문자를 하나씩 지우고 다시 
어느 한쪽을 먼저 스킵하지않고 각각을 스킵한 방법을 통해 가능 성을 파악해야함!!!
왼쪽과 오른쪽 스킵을 순차로 진행하지 않고 동시에 처리해야한다!
아래의 상황에서는 1이 나와야하는데, 왼쪽에서부터 스킵을 먼저하면 2가 나온다!
1
abcddcdba
*/

#include <iostream>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int T, ans;
string msg[30];
bool is_palin(string tmp){
    int lo = 0, hi = tmp.size()-1;
    while(lo <= hi){
        if(tmp[lo++]!=tmp[hi--]) {
            return false;
        }
    }
    return true;
}

bool can_palin(string tmp){
    int lo = 0, hi = tmp.size()-1;
    while (lo <= hi){
        if(tmp[lo] != tmp[hi]){
            int t_lo = lo + 1, t_hi = hi;
            bool check = true;
            while(t_lo <= t_hi){
                if(tmp[t_lo++] != tmp[t_hi--]) check = false;
            }
            if(check) return true;
            t_lo = lo, t_hi = hi - 1, check = true;
            while(t_lo <= t_hi){
                if(tmp[t_lo++] != tmp[t_hi--]) check = false;
            }
            if(check) return true;
            return false;
        }
        lo++;
        hi--;
    }
    return true;
}

int solve(string tmp){
    if(is_palin(tmp)) return 0;
    else if(can_palin(tmp)) return 1;
    else return 2;
}
int main()
{
	io;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>msg[i];
        cout<<solve(msg[i])<<"\n";
    }
	return 0;
}
