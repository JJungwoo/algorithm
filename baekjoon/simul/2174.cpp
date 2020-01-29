#include <iostream>
#include <vector>
using namespace std;
// 백준 2174 로봇 시뮬레이션
int A, B, N, M;
//가로A , 세로B, 로봇 N개, M개 명령
bool flag;
const int dy[] = {0,1,0,-1 };
const int dx[] = {1,0,-1,0 };
typedef struct {
	int num;
	int dir;
}NODE;
typedef struct {
	int y, x;
}INFO;
NODE map[102][102];
INFO _robot[102];			
void output() {
	for (int i = 1; i <= B; ++i) {
		for (int j = 1; j <= A; ++j) {
			cout << map[i][j].num << " " << map[i][j].dir << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void move_robot(int robot_num, char command, int remain) {
	int y = _robot[robot_num].y;
	int x = _robot[robot_num].x;
	if (command == 'F') {
		int ny = y + dy[map[y][x].dir];
		int nx = x + dx[map[y][x].dir];
		//	cout <<"loop: "<<loop<<" " <<ny << " " << nx << "\n";
		if (ny <= 0 || nx <= 0 || ny > B || nx > A) {
			cout << "Robot " << map[y][x].num << " crashes into the wall\n";
			flag = true;
			//for (remain++; remain < M; remain++) {
			//	int a, b, c;
			//	cin >> a >> b >> c;
			//}
			return;
		}
		else if (map[ny][nx].num  ) {
			cout << "Robot " << map[y][x].num << " crashes into robot " << map[ny][nx].num << "\n";
			flag = true;
			//for (remain++; remain < M; remain++) {
			//	int a, b, c;
			//	cin >> a >> b >> c;
			//}
			return;
		}
		map[ny][nx].num = map[y][x].num;
		map[ny][nx].dir = map[y][x].dir;
		_robot[robot_num].y = ny;
		_robot[robot_num].x = nx;
		map[y][x].num = 0;
		map[y][x].dir = 0;
	}else if (command == 'L') {
		map[y][x].dir = (map[y][x].dir + 1) % 4;
	}
	else if (command == 'R') {
		if (map[y][x].dir == 0) {
			map[y][x].dir = 3;
		}
		else {
			map[y][x].dir = map[y][x].dir - 1;
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//input
	cin >> A >> B;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		int y, x;
		char c;
		cin >> x>> y;
		cin >> c;
		map[y][x].num = i + 1;
		_robot[i + 1].y = y;
		_robot[i + 1].x = x;
		if (c == 'E') {
			map[y][x].dir = 0;
		}
		else if (c == 'W') {
			map[y][x].dir = 2;
		}
		else if (c == 'S') {
			map[y][x].dir = 1;
		}
		else if (c == 'N') {
			map[y][x].dir = 3;
		}
	}
	//output();
	for(int i=0; i<M; ++i){
		int robot, loop; char c;
		cin >> robot;
		cin >> c;
		cin >> loop;
		if (c == 'L' || c == 'R') {
			loop %= 4;
		}
		for(int k=0; k < loop; ++k){
			move_robot(robot, c,i);
			//output();
			if (flag) {
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	if (!flag) {
		cout << "OK\n";
	}
	return 0;
}