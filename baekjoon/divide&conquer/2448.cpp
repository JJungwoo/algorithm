/*
[boj] 2448. 별 찍기 - 11
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int star[5000][5000];
int n;
int main()
{
    io;
    for(int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            cout<<"*";
        }
        cout<<"\n";
    }

    return 0;
}