/*
[boj] 17088. 등차수열 변환
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n;
int numbers[100001];

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>numbers[i];
    }
    return 0;
}