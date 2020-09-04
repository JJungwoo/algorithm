/*
[boj] 2671. 잠수함식별
https://www.acmicpc.net/problem/2671
*/

#include <iostream>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

bool ans;
string stand[2][3] = {{"10", "0", "1"}, {"01"}};
// (100~1~|01)~

bool go(string s) {
    int N = s.length();
    if (N == 0) return true;
    if (N >= 4 && s[0] == '1' && s[1] == '0' && s[2] == '0') {
        int idx = 2;
        while (idx < N && s[idx] == '0') {
            idx++;
        };
        if (idx == N) return false;
        while (idx < N && s[idx] == '1') {
            idx++;
        };
        if (idx + 1 < N && s[idx] == '0' && s[idx + 1] == '0' && s[idx-2] =='1') return go(s.substr(idx - 1));
        else return go(s.substr(idx));
    }
    if (N >= 2 && s[0] == '0' && s[1] == '1') {
        return go(s.substr(2));
    }
    return false;
}

void solve(int idx, int type, int subcnt, string tmp) {
    if(idx > 200 || idx > tmp.length()) return ;
    if(idx == tmp.length()) {
        if(type == 0 && subcnt != 2) return ;
        ans = true;
        return ;
    }

    if(type == 0) {
        if(subcnt == 0 && tmp.substr(idx, 1).compare(stand[0][1]) == 0) {
            solve(idx + 1, 0, subcnt + 1, tmp);
        }
        if(subcnt == 1) {
            if(tmp.substr(idx, 1).compare(stand[0][1]) == 0)
                solve(idx + 1, 0, subcnt, tmp);
            if(tmp.substr(idx, 1).compare(stand[0][2]) == 0)
                solve(idx + 1, 0, subcnt + 1, tmp);
        }
        if(subcnt == 2) { 
            if(tmp.substr(idx, 1).compare(stand[0][2]) == 0)
                solve(idx + 1, 0, subcnt, tmp);
            if(tmp.substr(idx, 2).compare(stand[0][0]) == 0)
                solve(idx + 2, 0, 0, tmp); 
            if(tmp.substr(idx, 2).compare(stand[1][0]) == 0)
                solve(idx + 2, 1, 0, tmp);
        }
    }else if(type == 1) {
        if(tmp.substr(idx, 2).compare(stand[0][0]) == 0) {
            solve(idx + 2, 0, 0, tmp);
        }
        if(tmp.substr(idx, 2).compare(stand[1][0]) == 0) {
            solve(idx + 2, 0, 0, tmp);
        }
    }
}

int main() 
{
    io;
    string input;
    cin >> input;

    if(input.substr(0, 2).compare(stand[0][0]) == 0)
        solve(2, 0, 1, input);
    if(input.substr(0, 2).compare(stand[1][0]) == 0)
        solve(2, 1, 0, input);

    if(ans) cout << "SUBMARINE\n";
    else cout << "NOISE\n";
    return 0;
}

