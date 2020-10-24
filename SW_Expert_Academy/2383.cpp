/*
[swea] 2383. [모의 SW 역량테스트] 점심 식사시간
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5-BEE6AK0DFAVl
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int field[11][11];
int main() 
{
    io;
    int test_case;
	int T;
    cin >> T;
    for(test_case = 1; test_case <= T; ++test_case)
	{
        vector<pair<int, int> > v;
        vector<pair<pair<int, int>, int> > rooms;
        int N;
        cin >> N;
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                cin >> field[i][j];
                if(field[i][j] == 1) 
                    v.push_back(make_pair(i, j));
                else if(field[i][j] >= 2)
                    rooms.push_back(make_pair(make_pair(i, j), field[i][j]));
            }
        }
        queue<pair<int, int> > q[11]; // idx, time;
        int time = 0;
        while(true) {
            
            time++;
        }

        cout<<"#"<<test_case<<" "<<time<<"\n";
    }
    return 0;
}