/*
[BOJ] 1009. 분산처리
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int main()
{
    io;
    int t; cin>>t;
    while(t--){
        int a, b; cin>>a>>b;
        int data = 1;
        for(int i=0;i<b;i++){
            int tmp = (data * a) % 10;  
            data = tmp == 0 ? 10 : tmp;
        }
        cout<<data<<"\n";
    }

    return 0;
}