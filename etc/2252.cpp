/*
[BOJ] 2252 줄 세우기
*/
/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M;
stack<int> st;
bool visited[32000];
vector<int> relation[32000];

void dfs(int idx) {
	visited[idx] = true;
	for (int i = 0; i < relation[idx].size(); i++) {
		if (!visited[relation[idx][i]])
			dfs(relation[idx][i]);
	}
	st.push(idx);
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		relation[x].push_back(y);
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i])
			dfs(i);
	}
	while(!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
	return 0;
}

*/