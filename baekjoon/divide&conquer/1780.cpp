/*
[boj] 1780. 종이의 개수 
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, a,b,c;
int paper[2201][2201];
void find_paper(int x, int y, int num){
    if(num == 1) {
        if(paper[x][y] == -1){
            a++;
        }else if(paper[x][y] == 0){
            b++;
        }else {
            c++;
        }
        return;
    }

    int div = num/3;
    int tmp = paper[x][y];
    bool call = false;
    for(int i=x;i<x+num;i++){
        for(int j=y;j<y+num;j++){
            if(tmp != paper[i][j]) {
                call = true;
                break;
            }
        }
    }

    if(!call){
        if(tmp == -1){
            a++;
        }else if(tmp == 0){
            b++;
        }else {
            c++;
        }
        return;
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            find_paper(x+i*div, y+j*div, div);
        }
    }
}
int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>paper[i][j];
        }
    }
    find_paper(0,0,n);
    cout<<a<<"\n";
    cout<<b<<"\n";
    cout<<c<<"\n";
    return 0;
}