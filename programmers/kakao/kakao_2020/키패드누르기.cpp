/*
[programmers] 2020 카카오 인턴십. 키패드 누르기
https://programmers.co.kr/learn/courses/30/lessons/67256
*/
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
int map[4][3] = {
    {1,2,3},
    {4,5,6},
    {7,8,9},
    {10,0,11}
};
unordered_map<int, pair<int, int>> m;
inline int distance(int sx, int sy, int dx, int dy) {
    return abs(sx - dx) + abs(sy - dy);
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(int i=0;i<4;i++) {
        for(int j=0;j<3;j++) {
            m[map[i][j]] = {i, j};
        }
    }
    int left = 10, right = 11;
    for(int i : numbers) {
        if (i == 1 || i == 4 || i == 7) {
            left = i;
            answer += 'L';
            continue;
        } else if(i == 3 || i == 6 || i == 9) {
            right = i;
            answer += 'R';
            continue;
        }
        int move_left_cnt = distance(m[i].first, m[i].second,
                                    m[left].first, m[left].second);
        int move_right_cnt = distance(m[i].first, m[i].second,
                                    m[right].first, m[right].second);
        if (move_left_cnt == move_right_cnt) {
            if (hand == "left") {
                left = i;
                answer += 'L';
            }
            else {
                right = i;
                answer += 'R';
            }
        } else if (move_left_cnt < move_right_cnt) {
            left = i;
            answer += 'L';
        } else {
            right = i;
            answer += 'R';
        }
    }
    return answer;
}
