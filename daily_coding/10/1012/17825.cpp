/*
[boj] 17825. 주사위 윷놀이 
https://www.acmicpc.net/problem/17825
*/

#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int answer;
struct unit {
    bool live;
    int idx, sum;
};
vector<unit> units;
vector<int> dice(10, 0);
void init_map(pair<int, int> map[32]) {
    int stand = 2;
    for(int i=0;i<=20;i++) {
        map[i].first = i + 1;
        map[i].second = (stand * i);
    }   
    stand = 3;
    for(int i=0;i<2;i++) {
        map[21 + i].first = i+22;
        map[21 + i].second = 13 + (stand * i);
    }
    map[23].first = 29;
    map[23].second = 19;
    map[24].first = 25;
    map[24].second = 22;
    map[25].first = 29;
    map[25].second = 24;
    map[26].first = 27;
    map[26].second = 28;
    map[27].first = 28;
    map[27].second = 27;
    map[28].first = 29;
    map[28].second = 26;
    map[29].first = 30;
    map[29].second = 25;
    map[30].first = 31;
    map[30].second = 30;
    map[31].first = 20;
    map[31].second = 35;
    
    map[5].first = 21;
    map[10].first = 24;
    map[15].first = 26;
}

void simul(int dicecnt, int restcnt, int sum, pair<int, int> map[32], bool check_map[32]) {
    if(dicecnt == 0) {
        if(answer < sum) 
            answer = sum;
        return;
    }

    for(int i=0;i<units.size();i++) {
        for(int j=0;j<dice.size();j++) {
            if(units[i].live == false) continue;
            int midx = units[i].idx + dice[j];
            if(check_map[midx]) continue;
            check_map[midx] = true;
            simul(dicecnt - 1, );
        }
    }
}

void solve() {
    bool check_map[32] = {0, };
    pair<int, int> map[32];
    init_map(map);
    simul(10, dice[0], 0, map, check_map);
    cout<<answer<<"\n";
}

int main() 
{
    io;
    for(int i=0;i<10;i++) 
        cin >> dice[i];
    solve();
    return 0;
}

