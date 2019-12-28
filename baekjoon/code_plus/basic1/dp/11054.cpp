/*
[BOJ] 11054. 가장 긴 바이토닉 부분 수열
가장 긴 바이토닉 부분 수열: 
수열 S가 어떤 수 Sk를 기준으로 S1 < S2 < ... Sk-1 < Sk > Sk+1 > ... SN-1 > SN 인 수열
n개의 값이 주어지면 n번째 위치에는 최대 바이토닉 수열 길이를 저장하면 된다.
각각 dp 배열에 수열 값을 넣어주고 조건을 걸어서 바이토닉 수열인지 판별하고 바이토닉 수열이 되는 
상황만 더해서 결국 n 위치에 최대값이 오는 상황만 만들면 되지 않을까??.
++ 바이토닉 수열인지 판별을 위해 무언가 조건 혹은 표시가 필요하다.. dp 배열에 어떻게하면 표현할 수 있을까.
증가하는 방향과 감소하는 방향 표시가 필요하다.
n = 10
1 2 3 4 5 6 7 8 9 10
1 5 2 1 4 3 4 5 2 1
< : 1(1), 3(2), 6(3), 7(4), 8(5)
> : 2(5), 5(4), 6(3), 9(2), 10(1)
ans : 1(1), 3(2), 6(3), 7(4), 8(5), 9(2), 10(1) == 7
먼저 < 가 되는 수열 dp 먼저 구해보자.
dp[i] = 
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
vector<int> seq;
vector<int> ldp;
vector<int> rdp;

void solve()
{
    for(int i=1;i<=n;i++){
        ldp[i] = 1;
        for(int j=1;j<=i;j++){
            if(seq[j] < seq[i] && ldp[i] < ldp[j] + 1){
                ldp[i] = ldp[j] + 1;
            }
        }
    }
    for(int i=n;i>=1;i--){
        rdp[i] = 1;
        for(int j=n;j>=i;j--){
            if(seq[i] > seq[j] && rdp[j] + 1 > rdp[i]){
                rdp[i] = rdp[j] + 1;
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(ans < ldp[i] + rdp[i] - 1)
            ans = ldp[i] + rdp[i] - 1;
    }
    cout<<ans<<"\n";
}
int main()
{
    io;
    cin>>n;
    if(n==1 || n==2){
        cout<<n<<"\n";
        return 0;
    }
    seq.resize(n+1, 0);
    ldp.resize(n+1, 0);
    rdp.resize(n+1, 0);
    for(int i=1;i<=n;i++) cin>>seq[i];
    solve();
    
    return 0;
}