/*
[BOJ] 15658. 연산자 끼워넣기 (2)
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int a[12], op[4];
long long min_ans = 1e10, max_ans = -1e10;

long long calc(long long a, long long b, int op)
{
	// cout<<a<<" "<<b<<" , "<<op<<"\n";
	switch(op){
		case 1:
			return a+b;
		case 2:
			return a-b;
		case 3:
			return a*b;
		case 4:
			return a/b;
		default:
			break;
	}
	return 0;
}

void solve(int cnt, long long sum)
{
    if(cnt == n-1){
        min_ans = min_ans < sum ? min_ans : sum;
        max_ans = max_ans > sum ? max_ans : sum;
        return;
    }

    for(int i=0;i<4;i++){
        if(op[i]){
            op[i]--;
            solve(cnt+1, calc(sum, a[cnt+1], i+1));
            op[i]++;
        }
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<4;i++){
        cin>>op[i];
    }
    solve(0, a[0]);
    cout<<max_ans<<"\n"<<min_ans<<"\n";
    return 0;
}