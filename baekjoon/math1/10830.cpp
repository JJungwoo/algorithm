/*
[boj] 10830. 행렬 제곱
https://www.acmicpc.net/problem/10830
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, b;
int a[5][5];
int my_pow(int tmp[5][5], int div){
    if(div == 0) return 1;

    int result = my_pow(tmp)
    return 0;
}
int main()
{
	io;
    cin>>n>>b;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
	return 0;
}
