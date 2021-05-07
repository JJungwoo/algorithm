/*
[programmers] Summer/Winter Coding(~2018) 배달
https://programmers.co.kr/learn/courses/30/lessons/12978
*/
#include <iostream>
#include <vector>
using namespace std;
#define MAX_INT 1e9
int village[51][51];
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            if (i == j) village[i][j] = 0;
            else village[i][j] = MAX_INT;
        }
    }

    for(int i=0;i<road.size();i++) {
        int x = road[i][0], y = road[i][1], val = road[i][2];
        // if(village[x- 1][y - 1] < val)  continue;
        village[x-1][y-1] = val;
        village[y-1][x-1] = val;
    }

    for(int z=0;z<N;z++) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if (i == j) continue;
                village[i][j] = min(village[i][j], village[i][z] + village[z][j]);
            }
        }
    }

    for(int i=0;i<N;i++) {
        if (village[0][i] <= K) {
            answer++;
        }
    }

    return answer;
}
