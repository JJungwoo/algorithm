/*
[swea] 7782. 반장 선출 
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWsBNHuqMMADFARG&categoryId=AWsBNHuqMMADFARG&categoryType=CODE
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() 
{
    io;
    int test_case;
	int T;
    cin >> T;
    map<string, int> m;
    for(test_case = 1; test_case <= T; ++test_case)
	{
        int N, maxCnt = 0;
        cin >> N;
        cin.ignore();   // 버퍼 비우기 필요
        for(int i=0;i<N;i++) {
            bool visited[26];
            string input;
            int cnt = 0;
            getline(cin, input);
            fill(visited, visited+26, 0);
            for(auto it : input) {
                if(it != ' ' && !visited[it-'A']) {
                    visited[it-'A'] = true;
                    cnt++;
                }
            }
            if(maxCnt < cnt) maxCnt = cnt;
            m.insert(make_pair(input, cnt));
        }
        for(auto it : m) {
            if(it.second == maxCnt) {
                cout<<"#"<<test_case<<" "<<it.first<<"\n";
                break;
            }
        }
    }
    return 0;
}

