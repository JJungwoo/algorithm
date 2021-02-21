/*
[programmers] 2021 KAKAO BLIND RECRUITMENT 합승 택시 요금
https://programmers.co.kr/learn/courses/30/lessons/72413
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define MAX_INT 987654321
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = MAX_INT;
    vector<vector<int>> dist(n, vector<int>(n, MAX_INT));

    for(int i=0;i<n;i++)
        dist[i][i] = 0;

    for(auto it : fares) {
        dist[it[0]-1][it[1]-1] = it[2];
        dist[it[1]-1][it[0]-1] = it[2];
    }

    for(int k=0;k<n;k++) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i=0;i<n;i++)
        if(dist[s-1][i] + dist[i][a-1] + dist[i][b-1] > 0)
            answer = min(answer, dist[s-1][i] + dist[i][a-1] + dist[i][b-1]);

    return answer;
}
