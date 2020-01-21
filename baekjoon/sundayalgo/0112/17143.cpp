/*
[BOJ] 1051. 숫자 정사각형
음수 모듈 연산 방법
현재 인덱스에 *2를 한 다음 값에 이동할 만큼 값을 모듈연산해서 모듈연산 인덱스에 매칭해주면 됨.
ex)
0 1 2 3 4 5
0 9 8 7 6 5
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

// up down right left

struct shark{
    int x,y,s,d,z;
    bool live;
    shark(){}
    shark(int _x, int _y, int _s, int _d, int _z, bool _live) :
    x (_x), y (_y), s (_s), d (_d), z (_z), live (_live) {}
    // pos(x,y), speed, dir, size    
};

int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int r,c,m;  // r = x, c = y;
int king, flag = 1, ans, len, livesharks;
int kxp, kyp;
vector<shark> sharks;

inline void moveShark(int idx){
    //int mx = sharks[idx].x + (dir[sharks[idx].dir][0] * sharks[idx].s);
    //int my = sharks[idx].y + (dir[sharks[idx].dir][1] * sharks[idx].s);
    //int mx = (r * 2) % sharks[idx].x;
    if(sharks[idx].d <= 2){ // up down
        int my = sharks[idx].y + ((c * 2) % sharks[idx].s) - 1;
        //sharks[idx].y = my > c ? c -  : my;
    }else{  // right left

    }
}

inline void sharkMoveAndCrash(){
    for(int i=0;i<len;i++){
        moveShark(i);
    }
    for(int i=0;i<len-1;i++){
        if(sharks[i].live){
            for(int j=i+1;j<len;j++){
                if(sharks[i].x == sharks[j].x && sharks[i].y == sharks[j].y){
                    sharks[i].s > shark[j].s ? sharks[i].live = false : sharks[j].live = false;
                    livesharks--;
                    break;    
                }
            }               
        }
    }
}

int main()
{
    io;
    cin>>r>>c>>m;
    for(int i=0;i<m;i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;
        sharks.push_back(shark(a,b,c,d,e,true));
    }
    len = sharks.size();
    livesharks = len;
    while(1)
    {
        kyp = king;
        // catch shark
        for(int i=0;i<len;i++){
            if(sharks[i].live && sharks[i].x == )
        }

        sharkMoveAndCrash();

        if(!livesharks) {
            cout<<ans<<"\n";
            return 0;
        }
        if(king >= c) flag *= -1;
        else if(king <= 1) flag *= -1;
        king += (1 * flag);
    }

    return 0;
}