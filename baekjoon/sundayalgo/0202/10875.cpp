/*
[BOJ] 10875. 뱀
*/

#include <iostream>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


/*
struct snake{       // down, left, up, right
    int x, y, dir;
};
snake my;
int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
int l, n, ans;
int xl[100000001];
int yl[100000001];
bool live = true;
int main()
{
    io;
    my.x = 0, my.y = 0, my.dir = 0;
    cin>>l;
    cin>>n;
    for(int i=0;i<n;i++){
        int cnt;
        char tdir;
        cin>>cnt>>tdir;
        if(tdir == 'L'){
            my.dir = (my.dir + 1) % 4;
        }else if(tdir == 'R'){
            my.dir = (my.dir - 1 < 0 ? 3 : my.dir - 1);
        }
        my.x += (dir[my.dir][0] * cnt);
        my.y += (dir[my.dir][1] * cnt);
        cout<<"x: "<<my.x<<" y: "<<my.y<<" cnt:"<<cnt<<"\n";
        if(live && (my.x > l || my.x < -l)){
            cout<<"out x: "<<ans<<" , "<<cnt<<" abs: "<<abs(my.x - cnt)<<"\n";
            ans += cnt - abs(l - cnt) + 1;
            live = false;
        }else if(live && (my.y > l || my.y < -l)){
            cout<<"out y: "<<ans<<" , "<<cnt<<" abs: "<<abs(my.y - cnt)<<"\n";
            ans += cnt - abs(l - cnt) + 1;
            live = false;
        }
        if(live) ans += cnt;
            cout<<ans<<" , "<<cnt<<"\n";
    }
    cout<<ans<<"\n";

    return 0;
}
*/