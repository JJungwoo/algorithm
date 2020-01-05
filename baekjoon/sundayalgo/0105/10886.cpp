/*
[BOJ] 10886. 0 = not cute / 1 = cute
*/
#include <iostream>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int xcnt, bcnt;
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        if(input) bcnt++;
        else xcnt++;
    }
    cout<<(bcnt > xcnt ? "Junhee is cute!\n":"Junhee is not cute!\n");

    return 0;
}