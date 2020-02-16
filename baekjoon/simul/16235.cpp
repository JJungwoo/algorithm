/*
[BOJ] 16235. 나무 재테크
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m, k;
int mineral[11][11], map[11][11], deadw[11][11];
int dir[8][2] = {
    {-1,-1},{-1,0},{-1,1},
    {0,-1},{0,1},
    {1,-1},{1,0},{1,1}
    };

struct wood{
    int x,y,age;
    wood(int _x, int _y, int _age):x(_x), y(_y), age(_age) {};
    bool operator < (wood w) { return this->age <= w.age; }
};

vector<wood> vw;

bool compare(wood w1, wood w2){
    return (w1.age <= w2.age);
}

void print_map(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"live tree\n";
    for(int i=0;i<vw.size();i++){
        cout<<vw[i].x<<","<<vw[i].y<<":"<<vw[i].age<<"\n";
    }
}

void solve(){
    
    for(int i=1;i<=k;i++){
        vector<wood> d_vw;
    // spring 자신의 나이만큼 양분을 먹고 나이가 1 증가, 여러개 있을 경우 어린 나무부터 양분 섭취
    // 양분 부족시 죽음
        int vw_s = vw.size();
        for(int i=0;i<vw_s;i++){
            int x = vw[i].x, y = vw[i].y;
            if((map[x][y] - vw[i].age) >= 0 && vw[i].age > 0 && map[x][y] > 0){
                map[x][y] -= vw[i].age;
                vw[i].age++;
            }else{
                d_vw.push_back(wood(x,y,vw[i].age));
                vw[i].age = 0;
            }
        }

        print_map();

    // summer 봄에 죽은 나무가 양분으로 변함, 죽은 나무 나이/2가 양분
        int d_vw_s = d_vw.size();
        for(int i=0;i<d_vw_s;i++){
            int x = d_vw[i].x, y = d_vw[i].y, age = d_vw[i].age;
            map[x][y] += age/2;
        }

        cout<<"summer\n";
        print_map();
    // autumn 나무가 번식, 나무의 나이가 5의 배수이면 인접 8칸에 나이가 1인 나무 생성
        for(int i=0;i<vw_s;i++){
            if(vw[i].age > 0 && vw[i].age%5 == 0){
                cout<<vw[i].x<<" : "<<vw[i].y<<"\n";
                for(int j=0;j<8;j++){
                    int mx = vw[i].x + dir[j][0], my = vw[i].y + dir[j][1];
                    if(mx <= 0 || my <= 0 || mx > n || my > n) continue;
                    vw.push_back(wood(mx,my,1));
                    cout<<"incre : "<<mx<<","<<my<<"\n";
                }
            }
        }

    // winter 양분을 추가, 각 칸에 양분이 A[r][c] 배열의 크기 만큼 추가된다.
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                map[i][j] += mineral[i][j];
            }
        }
        sort(vw.begin(), vw.end(), compare);
        // live woods remove
        cout<<"remove\n";
        int s = vw.size();
        cout<<"size : "<<s<<"\n";
        bool check = false;
        for(int i=0;i<s;i++){
            cout<<vw[i].age<<"\n";
            if(vw[i].age == 0) {
                check = true;
                s = i;
            }else break;
        }
        if(check) vw.erase(vw.begin()+s);
    }
    
}

int main()
{
    io;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>mineral[i][j];
            map[i][j] = mineral[i][j] + 5;
        }
    }

    for(int i=1;i<=m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        vw.push_back(wood(x,y,z));
    }
    print_map();
    solve();
    int ans = vw.size();
    cout<<"\n"<<ans<<"\n";

    return 0;
}