/*
[boj] 9019. DSLR
¸ØÃß´Â Á¶°Ç..
0 ~ 10,000
 n = ((d1 ¡¿ 10 + d2) ¡¿ 10 + d3) ¡¿ 10 + d4
 D : n*2 > 9999 ? n*2%10000 : n*2;
 S : n-1 <= 0 ? 9999 : n-1;
 L : 1234 <- 2341  
 R : 1234 -> 4123
 A -> B
*/
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int A, B, ans = 987654321;
int visited[10000];
string sans;
// D, S, L, R = 0, 1, 2, 3;

struct cmds {
	int a, cnt;
	string cmd;
};

void solve() {
	queue<cmds> q;
	q.push({ A, 0, "" });
	visited[A] = true;
	while (!q.empty()) {
		int qvalue = q.front().a, cnt = q.front().cnt;
		string cmd = q.front().cmd;
		q.pop();
		if (qvalue == B) {
			//cout << qvalue<<","<<ans << "," << sans << ":" << cmd << "\n";
			if (ans > cnt) {
				ans = cnt;
				sans = cmd;
				//cout << ans << "," << sans <<":"<<cmd<< "\n";
			}
			break;
		}
		for (int i = 0; i< 4; i++) {
			int move = qvalue;
			string tmp = cmd;
			int d1 = (move / 1000), d2 = ((move % 1000) / 100), d3 = ((move % 100) / 10), d4 = (move % 10);
			//n = ((d1 ¡¿ 10 + d2) ¡¿ 10 + d3) ¡¿ 10 + d4
			//D: n * 2 > 9999 ? n * 2 % 10000 : n * 2;
			//S: n - 1 <= 0 ? 9999 : n - 1;
			//L: 1234 <- 2341
			//R: 1234 -> 4123
			switch (i) {
			case 0:		// D
				move = (move * 2 > 9999 ? move * 2 % 10000 : move * 2);
				tmp += 'D';
				break;
			case 1:		// S
				move = (move - 1 <= 0 ? 9999 : move - 1);
				tmp += 'S';
				break;
			case 2:		// L
				move = ((d2 * 10 + d3) * 10 + d4) * 10 + d1;
				tmp += 'L';
				break;
			case 3:		// R
				move = ((d4 * 10 + d1) * 10 + d2) * 10 + d3;
				tmp += 'R';
				break;
			}
			if (visited[move]) continue;
			visited[move] = true;
			q.push({ move, cnt + 1, tmp });
		}
	}
}

int main()
{
	io;
	int T; cin >> T;
	while (T--) {
		cin >> A >> B;	// A -> B
		memset(visited, 0, sizeof(visited));
		ans = 987654321;
		sans = "";
		solve();
		cout << sans << "\n";
	}
	return 0;
}

/*
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int t;
bool visited[10000];
int A, B;
vector<char> cmd;
char cmd_char[] = "DSLR";

void dfs(int x)
{
	if (x == B) {
		for (int i = 0; i < cmd.size(); i++) {
			cout << cmd[i];
		}
		cout << "\n";
		return;
	}

	int mx[4] = {
		x * 2 % 10000, 
		x - 1 <= 0 ? x = 9999 : x - 1,
		x % 1000 * 10 + x / 1000, 
		x / 10 + x % 10 * 1000
	};
	
	for (int i = 0; i < 4; i++) {
		//cout << cmd_char[i]<< ":"<<mx[i] << "\n";
		if (visited[mx[i]]) continue;
		visited[mx[i]] = true;
		cmd.push_back(cmd_char[i]);
		dfs(mx[i]);
		cmd.pop_back();
		visited[mx[i]] = false;
	}

}

int main()
{
	io;
	cin >> t;
	while (t--) {
		cin >> A >> B;
		memset(visited, 0, sizeof(visited));
		dfs(A);
	}

	return 0;
}
*/