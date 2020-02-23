/*
[BOJ] 2580. 스도쿠
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int map[9][9], tmp_map[9][9], ans_cnt;
int check_map[10];
vector<pair<pair<int, int>, pair<int, int> > > vp;
bool visited[81];

bool check_square(int x, int y)
{
    int nx = (x / 3) * 3; // 0, 1, 2
    int ny = (y / 3) * 3;
    int number[10] = {0,};
    for(int i=nx;i<nx+3;i++){
        for(int j=ny;j<nx+3;j++){
            if(number[tmp_map[i][j]] == 0){
                number[tmp_map[i][j]] = 1;
            }else {
                return false;
            }
        }
    }
    return true;
}

bool check_linear(int x, int y)
{
    int xnumber[10] = {0,};
    int ynumber[10] = {0,};
    for(int i=0;i<9;i++){
        if(xnumber[tmp_map[x][i]] == 0){
            xnumber[tmp_map[x][i]] = 1;
        }else if(xnumber[tmp_map[x][i]] == 1){
            return false;
        }
        if(ynumber[tmp_map[i][y]] == 0){
            ynumber[tmp_map[i][y]] = 1;
        }else if(ynumber[tmp_map[i][y]] == 1){
            return false;
        }
    }
    return true;
}

void solve(int cnt){
    if(cnt == ans_cnt){
        for(int i=0;i<vp.size();i++){
            int x = vp[i].first.first;
            int y = vp[i].first.second;
            cout<<cnt<<","<<visited[cnt]<<" "<<x<<","<<y<<" : "<<tmp_map[x][y]<<"\n";
            if(check_square(x,y) == false) return;
            if(check_linear(x,y) == false) return;
        }
        //cout<<"check\n";
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                map[i][j] = tmp_map[i][j];
                cout<<tmp_map[i][j]<<" ";
            }
            cout<<"\n";
        }
        return;
    }

    for(int i=1;i<=9;i++){
        //if(!visited[i] && 
        if(check_map[i] >= 0 && !visited[cnt]){
            visited[cnt] = true;
            //cout<<i<<"\n";
            vp[cnt].second.second = i;
            tmp_map[vp[cnt].first.first][vp[cnt].first.second] = i;
            check_map[i]--;
            solve(cnt+1);
            check_map[i]++;
            visited[cnt] = false;
        }
    }
}

int main()
{
    io;
    for(int i=0;i<=9;i++){
        check_map[i] = 9;
    }
    cout<<"\n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>map[i][j];
            tmp_map[i][j] = map[i][j];
            check_map[map[i][j]]--;
            if(map[i][j] == 0){
                ans_cnt++;
                vp.push_back(make_pair(make_pair(i, j), make_pair(0, 0)));
            }
        }
    }
    for(int i=0;i<vp.size();i++){
        int x = vp[i].first.first;
        int y = vp[i].first.second; 
        cout<<x<<", "<<y<<"\n";
    }
    cout<<ans_cnt<<","<<vp.size()<<"\n";
    solve(0);
    cout<<"\n\n";

    int cnt = 0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            //if(map[i][j]){
                cout<<tmp_map[i][j]<<" ";
            /*}else {
                cout<<vp[i].second.second<<" ";
                cnt++;
            }*/
        }
        cout<<"\n";
    }
    return 0;
}