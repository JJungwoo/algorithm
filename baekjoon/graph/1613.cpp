/*
[boj] 1613. 역사
https://www.acmicpc.net/problem/1613
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, k, s;
bool arr[401][401];
int main() 
{
    io;
    cin >> n >> k;
    for(int i=0;i<k;i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
    }

    for(int k=1;k<=n;k++) {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(!arr[i][j]) {
                    if (arr[i][k] && arr[k][j]) 
                        arr[i][j] = true;
                }
            }
        }
    }
    cin >> s;
    for(int i=0;i<s;i++) {
        int a, b;
        cin >> a >> b;
        if(arr[a][b]) cout<<"-1\n";
        else if(arr[b][a]) cout<<"1\n";
        else cout<<"0\n";
    }
    return 0;
}
