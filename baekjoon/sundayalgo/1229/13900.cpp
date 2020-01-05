/*
[BOJ] 13900. 순서쌍의 곱의 합
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

long long ans;
int n;
vector<int> a;
vector<long long> sum;

void solve(){
    for(int i=1;i<n;i++){
        sum[i] += sum[i-1] + a[i-1]; 
        ans += sum[i] * a[i];        
    }
}

int main(){
    io;
    cin>>n;
    a.resize(n+1);
    sum.resize(n+1);
    for(int i=0;i<n;i++) cin>>a[i];
    solve();
    cout<<ans<<"\n";
    return 0;
}