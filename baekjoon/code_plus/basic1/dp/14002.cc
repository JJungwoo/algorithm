/*
[BOJ] 14002. 가장 긴 증가하는 부분 수열 4
*/
#include <iostream>
using namespace std;
int main()
{
    int A[1000] = { 0, };
    int lis[1000] = { 0, };
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int i = 1, j = 0;
    lis[0] = A[0];
    while (i < n) {
        if (A[i] > lis[j]) {
            lis[j + 1] = A[i];
            j++;
        }
        else {
            int lo = 0, hi = j;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (lis[mid] < A[i])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            lis[lo] = A[i];
        }
        i++;
    }
    cout << j+1 << '\n';
    for(int z=0;z<=j;z++) cout<<lis[z]<<" ";
    return 0;
}

