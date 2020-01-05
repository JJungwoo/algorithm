/*
[BOJ] 8741. 이진수 합
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cout<<"1";
    for(int j=1;j<n;j++) cout<<"0";
    cout<<"\n";
    return 0;
}
/*
typedef long long ll;
vector<int> ans;

void ttob(ll num){
    ll sum = 0;
    while(num/2){
        //cout<<num<<":"<<num%2<<"\n";
        ans.push_back(num%2);
        sum += num%2*2;
        num /= 2;
    }
    ans.push_back(num%2);
}

int btot(ll num){
    int result = 0, mul = 0, sum = 0;
    while(num--){
        sum += pow(2, mul);
        //cout<<sum<<","<<mul<<","<<num<<"\n";
        mul++;
    }
    for(int i=1;i<=sum;i++)
        result += i;   
    return result;
}

int main()
{
    io;
    ll n;
    cin>>n;
    ttob(btot(n));
    int size = ans.size();
    for(int i=size-1;i>=0;i--)
        cout<<ans[i];
    cout<<"\n";
    return 0;
}
*/