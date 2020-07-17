/*
[boj] 15973. 두 박스
https://www.acmicpc.net/problem/15973

FACE: 두 박스가 겹침
LINE: 두 박스가 선분에서 만남
POINT: 두 박스가 한점에서 만남
NULL: 두 박스가 만나지 않음
왼쪽 아래, 오른쪽 위
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
struct box{
    ll x1, x2, y1, y2;
};
char box_status[4][6] = {"FACE", "LINE", "POINT", "NULL"};
int check_status(box p, box q){
    if(p.x1 == q.x2 || p.x2 == q.x1) {
        if(p.y1 == q.y2 || p.y2 == q.y1) return 2;
        else if((p.y2 - p.y1) + (q.y2 - q.y1) > max(q.y1 - p.y1, p.y2 - q.y1)) return 1;
    }
    else if((p.x2 - p.x1) + (q.x2 - q.x1) > max(q.x2 - p.x1, p.x2 - q.x1)) {
        if (p.y1 == q.y2 || p.y2 == q.y1) return 1;
        else if ((p.y2 - p.y1) + (q.y2 - q.y1) > max(q.y2 - p.y1, p.y2 - q.y1)) return 0;
    }
    return 3;
}
int main()
{
    io;
    box p, q;
    cin>>p.x1>>p.y1>>p.x2>>p.y2;
    cin>>q.x1>>q.y1>>q.x2>>q.y2;
    cout<<box_status[check_status(p, q)]<<"\n";
    return 0;
}