
/*
[BOJ] 16235. 나무 재테크
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m, k, change;
int mineral[11][11], map[11][11];
int dir[8][2] = {
    {-1,-1},{-1,0},{-1,1},
    {0,-1},{0,1},
    {1,-1},{1,0},{1,1}
};

struct wood{
    int x,y,age;
    wood(int _x, int _y, int _age):x(_x), y(_y), age(_age) {};
    bool operator < (wood w) { return this->age < w.age; }
};

vector<wood> g_vw[2];

bool compare(wood w1, wood w2){
    return (w1.age < w2.age);
}

void solve(){

    sort(g_vw[0].begin(), g_vw[0].end(), compare);

    for(int i=1;i<=k;i++){
        vector<wood>& vw = g_vw[change];
        vector<wood>& inc_vw = g_vw[1 - change];

        inc_vw.clear();

    // spring 자신의 나이만큼 양분을 먹고 나이가 1 증가, 여러개 있을 경우 어린 나무부터 양분 섭취
    // 양분 부족시 죽음
        for(int i=0;i<vw.size();i++){
            int x = vw[i].x, y = vw[i].y;
            if((map[x][y] >= vw[i].age) && vw[i].age > 0 && map[x][y] > 0){
                map[x][y] -= vw[i].age;
                vw[i].age++;
                // autumn 나무가 번식, 나무의 나이가 5의 배수이면 인접 8칸에 나이가 1인 나무 생성
        
                if(vw[i].age%5 == 0){
                //cout<<vw[i].x<<" : "<<vw[i].y<<"\n";
                    for(int j=0;j<8;j++){
                        int mx = x + dir[j][0], my = y + dir[j][1];
                        if(mx <= 0 || my <= 0 || mx > n || my > n) continue;
                        inc_vw.push_back(wood(mx,my,1));
                        //cout<<"incre : "<<mx<<","<<my<<"\n";
                    }
                }
            }else{
                vw[i].age = -vw[i].age;
            }
        }

    // summer 봄에 죽은 나무가 양분으로 변함, 죽은 나무 나이/2가 양분

        for(int i=0;i<vw.size();i++){
            if(vw[i].age < 0){
                int x = vw[i].x, y = vw[i].y, age = vw[i].age;
                map[x][y] += -age/2;
            }else{
                inc_vw.push_back(vw[i]);
            }
        }

    // winter 양분을 추가, 각 칸에 양분이 A[r][c] 배열의 크기 만큼 추가된다.
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                map[i][j] += mineral[i][j];
            }
        }
      
        change = 1 - change;
    }
    
}

int main()
{
    io;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mineral[i][j];
            map[i][j] = 5;
        }
    }

    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        g_vw[0].push_back(wood(x,y,z));
    }
    solve();
    int ans = g_vw[change].size();
    cout<<ans<<"\n";

    return 0;
}