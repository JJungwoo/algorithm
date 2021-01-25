/*
[boj] 7682. 틱택토
https://www.acmicpc.net/problem/7682
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
set<string> s;
/*
. . . 0 1 2
. . . 3 4 5
. . . 6 7 8
*/
inline int possible_game(vector<char> &map, int val) {
    int cnt = 0;
    char ret[10];
    if(map[0] != '.' && map[1] != '.' && map[2] != '.' && 
        map[0] == map[1] && map[1] == map[2]) {
            ret[cnt] = map[0]; cnt++;
        }
    if(map[3] != '.' && map[4] != '.' && map[5] != '.' && 
        map[3] == map[4] && map[4] == map[5]) {
            ret[cnt] = map[3]; cnt++;
        }
    if(map[6] != '.' && map[7] != '.' && map[8] != '.' && 
        map[6] == map[7] && map[7] == map[8]) {
            ret[cnt] = map[6]; cnt++;
        }

    if(map[0] != '.' && map[3] != '.' && map[6] != '.' && 
        map[0] == map[3] && map[3] == map[6]) {
            ret[cnt] = map[0]; cnt++;
        }
    if(map[1] != '.' && map[4] != '.' && map[7] != '.' &&         
        map[1] == map[4] && map[4] == map[7]) {
            ret[cnt] = map[1]; cnt++;
        }
    if(map[2] != '.' && map[5] != '.' && map[8] != '.' && 
        map[2] == map[5] && map[5] == map[8]) {
            ret[cnt] = map[2]; cnt++;
        }

    if(map[0] != '.' && map[4] != '.' && map[8] != '.' && 
        map[0] == map[4] && map[4] == map[8]) {
            ret[cnt] = map[0]; cnt++;
        }
    if(map[2] != '.' && map[4] != '.' && map[6] != '.' && 
        map[2] == map[4] && map[4] == map[6]) {
            ret[cnt] = map[2]; cnt++;
        }

    if(cnt > 0) {
        char tmp = ret[0];
        for(int i=1;i<cnt;i++) if(tmp != ret[i]) return 0;
        if((val+1) % 2 != 0 && ret[0] == 'O'
         || (val+1) % 2 == 0 && ret[0] == 'X') return 0;
    }
    else
        for(auto c : map) if(c == '.') return 0;
    return 1;
}
int main()
{
    io;
    int idx = 0;
    string input;
    vector<char> ex(9);
    vector<int> seq(9);

    for(int i=0;i<9;i++) {
        seq[i] = i;
        ex[i] = '.';
    }
    do{
        vector<char> tmp_ex = ex;
        for(int i=0;i<9;i++) {
            ((i+1) % 2 != 0) ? tmp_ex[seq[i]] = 'X' : tmp_ex[seq[i]] = 'O';
            if(possible_game(tmp_ex, i) == 1) {
                string tmp = "";
                for(auto c : tmp_ex)
                    tmp += c;
                
                if(s.find(tmp) == s.end())
                    s.insert(tmp);
            }
        }
    }while(next_permutation(seq.begin(), seq.end()));

    while(true) {
        cin >> input;
        if(!input.compare("end")) break;
        if(s.find(input) != s.end()) cout<<"valid\n";
        else cout<<"invalid\n";
    }
    return 0;
}