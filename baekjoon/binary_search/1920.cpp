/*
[boj] 1920. 수 찾기
https://www.acmicpc.net/problem/1920
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m, tmp;
int A[100005];
bool find_value(int *target, int value)
{
    int left = 0, right = n-1;
    while(left <= right){
        int mid = (left+right)/2;
        if(A[mid] == value)
            return true;
        else if(A[mid] > value)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>A[i];
    sort(A, A + n);
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>tmp;
        cout<<find_value(A, tmp)<<"\n";
    }
    return 0;
}