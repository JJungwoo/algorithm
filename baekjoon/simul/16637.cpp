/*
[boj] 16637. 괄호 추가하기
무엇을 기준으로 조합을 돌려야 할지.. 
자세히 보면 괄호는 중첩이 불가능하고 무조건 하나만 사용 가능하다.
이 점을 잘 활용해야 한다. 자신의 위치를 기준으로 이전 값과 이후 값 둘중 하나와
괄호로 묶여 먼저 계산이 된다.
*/
#include <iostream>
#include <vector>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, ans = -987654321, opsize;
vector<int> numbers;
vector<char> ops;
bool visited[20];

inline int cal(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
	return 0;
}

void solve(int cnt, int sum) {
	if (cnt == opsize) {
		//cout << sum << "\n";
		if (ans < sum) {
			ans = sum;
		}
		return;
	}

	//cout << cnt << ", " << sum << " "<< ops[cnt] <<" " << numbers[cnt + 1] 
	//	<< "=" << cal(sum, numbers[cnt + 1], ops[cnt]) << "\n";

	solve(cnt + 1, cal(sum, numbers[cnt + 1], ops[cnt]));

	if (cnt <= opsize - 2) {
		int next_sum = cal(sum, cal(numbers[cnt + 1], numbers[cnt + 2], ops[cnt + 1]), ops[cnt]);
		solve(cnt + 2, next_sum);
	}
}
int main()
{
	io;
	cin >> n;
	string msg;
	cin >> msg;
	for (int i = 0; i < n; i++) {
		if ((i+1) % 2 == 0) ops.push_back(msg[i]);
		else numbers.push_back(msg[i] - '0');
	}
	opsize = ops.size();
	solve(0, numbers[0]);
	cout << ans << "\n";
	return 0;
}


/*
void solve(int cnt, int arr[10], int tmp[10]) {
	if (cnt >= 5) {
		for (int i = 0; i < cnt; i++) {
			cout << tmp[i] << " ";
		}
		cout << "\n";
		return;
	}

	tmp[cnt] = arr[cnt];
	//cout << cnt << "\n";
	//cout << tmp[cnt] << "," << arr[cnt] << "\n";
	solve(cnt + 1, arr, tmp);
	tmp[cnt] = 0;

	tmp[cnt + 2] = arr[cnt];
	solve(cnt + 2, arr, tmp);
	tmp[cnt] = 0;
}


int main()
{
	io;
	int arr[10] = { 0, }, tmp[10] = { 0, };
	for (int i = 0; i < 5; i++) {
		arr[i] = i;
	}
	solve(0, arr, tmp);

	return 0;
}
*/
/*
#include <iostream>
#include <vector>
#include <string>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, ans;
vector<int> numbers;
vector<char> sign;

int cal(int a, int b, char sign) {

}

void solve(int cnt, int sum) {
	if (cnt == numbers.size()) {
		if (ans < sum) {
			ans = sum;
		}
		return;
	}

	solve(cnt + 1, cal(sum, numbers[cnt + 1], sign[cnt]));
	solve(cnt + 1, );
}

int main()
{
	io;
	cin >> n;
	string msg;
	cin >> msg;
	for (int i = 0; i < msg.size(); i++) {
		if ((i + 1) % 2 == 0) {
			sign.push_back(msg[i]);
		}
		else {
			numbers.push_back(msg[i] - '0');
		}
	}
	solve(0, numbers[0]);
	cout << ans << "\n";
	return 0;
}

*/
/*
#include <iostream>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n;
string msg;

bool visited[10];
vector<char> symbol;
vector<int> value;

void solve(int cur, int cnt) {
	if (cnt == n) {
		for (int i = 0; i < list.size(); i++) {
			cout << list[i] << " ";
		}
		cout << "\n";
		return;
	}

	int size = 
	for (int i = cur; i < size; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		list.push_back(i);
		solve(i + 1, cnt + 1);
		list.pop_back();
		visited[i] = false;
	}
}

int main()
{
	io;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i & 2 == 0) {
			char tmp; cin >> tmp;
			symbol.push_back(tmp);
		}
		else {
			int tmp; cin >> tmp;
			value.push_back(tmp);
		}
	}
	solve(0, 0);

	return 0;
}

*/