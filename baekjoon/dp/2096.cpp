/*
[boj] 2096. 내려가기
https://www.acmicpc.net/problem/2096
*/

#include <bits/stdc++.h>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAX_INT 1e9
int N;
int min_A, min_B, min_C;
int max_A, max_B, max_C;
int min_ans = MAX_INT, max_ans;
inline int compare(int a, int b, int c, char op) {
    if (op == '+') {   // 최대
        return (a > b ? (a > c ? a : c) : (b > c ? b : c));
    } else {    // 최소
        return (a < b ? (a < c ? a : c) : (b < c ? b : c));
    }
}
int main() 
{
    io;
    cin >> N;
    cin >> min_A >> min_B >> min_C;
    max_A = min_A, max_B = min_B, max_C = min_C;
    for(int i=0;i<N-1;i++) {
        int a, b, c; cin >> a >> b >> c;
        int tmp_min_A, tmp_min_B, tmp_min_C;
        int tmp_max_A, tmp_max_B, tmp_max_C;
        tmp_min_A = compare(min_A + a, min_B + a, MAX_INT, '-');
        tmp_min_B = compare(min_A + b, min_B + b, min_C + b, '-');
        tmp_min_C = compare(min_B + c, min_C + c, MAX_INT, '-');
        
        tmp_max_A = compare(max_A + a, max_B + a, 0, '+');
        tmp_max_B = compare(max_A + b, max_B + b, max_C + b, '+');
        tmp_max_C = compare(max_B + c, max_C + c, 0, '+');
        min_A = tmp_min_A, min_B = tmp_min_B, min_C = tmp_min_C; 
        max_A = tmp_max_A, max_B = tmp_max_B, max_C = tmp_max_C; 
    }
    cout<<compare(max_A, max_B, max_C, '+')<<" "<<compare(min_A, min_B, min_C, '-')<<"\n";
    return 0;
}
