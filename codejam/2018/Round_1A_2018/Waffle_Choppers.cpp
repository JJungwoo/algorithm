// row 나 col 로 나눴을 때, 동일한 초코칩의 갯수가 나와야함.
// row, col 순서를 기준으로 해서 각 셀의 초코칩을 계산


#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);


int main()
{
    io;

    return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int r, c, h, v, choco_cnt;
bool check, visited[100][100];
char map[100][100];
int div[100][100];

void print_map(bool tmp[100][100]){
    cout<<"print_map\n";
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<tmp[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void solve(int x, int y, int cnt){
    if(cnt == h+v){
        vector<int> choco;
        cout<<cnt<<"\n";
        //print_map(visited);
        int ch_cnt = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(map[i][j] == '@') ch_cnt++;
                //cout<<map[i][j]<<","<<i<<":"<<j<<"="<<ch_cnt<<"\n";
                if(visited[i][j]){
                    choco.push_back(ch_cnt);
                    ch_cnt = 0;
                }
            }
        }
        int size = choco.size(), tmp = choco[0];
        //cout<<size<<"\n";
        for(int i=1;i<size;i++){
            //cout<<tmp<<","<<i<<":"<<choco[i]<<"\n";
            if(tmp != choco[i]){
                return;
            }
        }
        check = true;
        return;
    }

    for(int i=x;i<r;i++){
        for(int j=y;j<c;j++){
            if(visited[i][j])continue;
            visited[i][j] = true;
            //div[i][j] = 
            solve(i, j, cnt+1);
            visited[i][j] = false;
        }
    }
}

int main(){
    io;
    int tcase;
    cin>>tcase;
    for(int i=1;i<=tcase;i++){
        cin>>r>>c>>h>>v;
        for(int x=0;x<r;x++){
            for(int y=0;y<c;y++){
                cin>>map[x][y];
                if(map[x][y] == '@') choco_cnt++;
            }
        }
        if(choco_cnt == 0){
            cout<<"check\n";
            check = true;
        }else {
            solve(0,0,0);
        }
        cout<<"Case #"<<i<<": "<<(check == true ? "POSSIBLE" : "IMPOSSIBLE")<<"\n";
    }

    return 0;
}
*/