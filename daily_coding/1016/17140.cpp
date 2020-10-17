/*
[boj] 17140. 이차원 배열과 연산 
https://www.acmicpc.net/problem/17140
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int R, C, K, row, col;  // 행, 열
int map[101][101][2];
// 나온 수, 나온 횟수
bool cmp(pair<int, int> A, pair<int, int> B) {
    if(A.second == B.second) return A.first < B.first;
    else return A.second < B.second;
}
inline bool check_array(int x, int y, int target, int stand) {
    cout<<"check_array : "<<x<<" "<<y<<" "<<target<<" == "<<map[x][y][stand]<<"\n";
    if(map[x][y][stand] == target) return true;
    else return false;
}
void print_map(int stand) {
    cout<<"print_map()\n";
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<map[i][j][stand]<<" ";
        }
        cout<<"\n";
    }
}
void roperation(int stand) {
    int maxidx = 0;
    cout<<"R\n";
    for(int i=0;i<row;i++) {
        vector<pair<int, int> > v;
        unordered_map<int, int> umap;
        for(int j=0;j<col;j++) {
            if(map[i][j][stand] == 0) continue;
            umap[map[i][j][stand]]++;
        }
        for(auto it : umap) {
            cout<<it.first<<" "<<it.second<<"\n";
            v.push_back(make_pair(it.first, it.second));
        }
        sort(v.begin(), v.end(), cmp);
        int idx = 0;
        for(auto it : v) {
            if(idx > 100) break;
            map[i][idx++][stand^1] = it.first;
            map[i][idx++][stand^1] = it.second;
        }
        maxidx = max(idx, maxidx);
    }
    col = maxidx;
}
void coperation(int stand) {
    int maxidx = 0;
    cout<<"C\n";
    for(int j=0;j<col;j++) {
        vector<pair<int, int> > v;
        unordered_map<int, int> umap;
        for(int i=0;i<row;i++) {
            if(map[i][j][stand] == 0) continue;
            umap[map[i][j][stand]]++;
        }
        for(auto it : umap) {
            cout<<it.first<<" "<<it.second<<"\n";
            v.push_back(make_pair(it.first, it.second));
        }
        sort(v.begin(), v.end(), cmp);
        int idx = 0;
        for(auto it : v) {
            if(idx > 100) break;
            map[idx++][j][stand^1] = it.first;
            map[idx++][j][stand^1] = it.second;
        }
        maxidx = max(idx, maxidx);
    }
    row = maxidx;
}
void clear_map(int stand) {
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            map[i][j][stand^1] = 0;
        }
    }
}
void solve() {
    int answer = -1, cur = 0;
    for(int i=1;i<=4;i++) {
        if(row >= col) {
            roperation(cur);
        }else if(row < col) {
            coperation(cur);
        }
        cur ^= 1;
        print_map(cur);
        //print_map(cur^1);
        if(check_array(R, C, K, cur)){
            answer = i;
            break;
        }
        clear_map(cur);
        //copy_and_paste(cur);
        //cur ^= 1;
    }
    cout<<answer<<"\n";
}
int main() 
{
    io;
    cin >> R >> C >> K;
    R--, C--;
    row = 3, col = 3;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cin >> map[i][j][0];
        }
    }
    if(check_array(R, C, K, 0)) {
        cout<<"0\n";
    }else{
        solve();
    }
    return 0;
}