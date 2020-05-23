/*
[boj] 2447. 별 찍기 - 10
*/

#include <iostream>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n;
char star[2201][2201];
void set_star(int x, int y, int num){

    if(num == 1) {
        star[x][y] = '*';
        return;
    }

    int div = num/3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i == 1 && j == 1) continue;
            else {
                set_star(x+i*div, y+j*div, div);
            }
        }
    }
}
int main()
{
    io;
    cin>>n;
    memset(star, ' ', sizeof(star));
    set_star(0,0,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<star[i][j];
        }
        cout<<"\n";
    }
    return 0;
}