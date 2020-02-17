/*
[BOJ] 16637. 괄호 추가하기
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

char formula[19];
int number[19], result[19];
int n, fcnt, ncnt, ans;
bool visited[19];

int calc(int a, int b, char form){
    int res = 0;

    switch(form){
        case '+';
        res = a+b;
        break;
        case '-';
        res = a-b;
        break;
        case '*';
        res = a*b;
        break;
    }

    return res;
}

void solve(int cnt, int sum){
    if(cnt == fcnt){
        ans = max(ans, sum);
    }

    for(int i=0;i<ncnt;i++){
        if(!visited[i]){
            visited[i] = true;
            
            visited[i] = false;
        }
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        if(i%2==0) cin>>formula[fcnt++];
        else cin>>number[ncnt++];
    }
    solve(0);
    cout<<ans<<"\n";
    return 0;
}