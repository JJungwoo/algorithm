/*
[BOJ] 10972. 다음 순열
c++의 STL algorithm 헤더 내부 next_permutation 함수로 풀 수 있다.
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
오름차순을 내림차순으로 바꿔가며 사전순으로 나열한다.

*/
#include <iostream>
#include <algorithm>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int seq[10001]

bool next_permutation()
{
    int i = n;
    while(i > 1 && seq[i] <= seq[i-1]){    // 뒤에서부터 오름차순으로 되어 있는 순열 찾기.
        i--;
    }
    if(i <= 1){
        return false;
    }
    int j = n;
    while(seq[i-1] >= seq[j]){
        j--;
    }
    swap(seq[i-1], seq[j]);
    j = n;
    while(i < j){
        swap(seq[i], seq[j]);
        i++;
        j--;
    }
    return true;
}

int main()
{
    io;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>seq[i];
 
    if(next_permutation()) {
        for(int i=1;i<=n;i++){
            cout<<seq[i]<<" ";
        }
        cout<<"\n";
    }else{
        cout<<"-1\n";
    }



    return 0;
}