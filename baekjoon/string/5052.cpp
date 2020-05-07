/*
[boj] 5052. 전화번호 목록
*/
#include <iostream>
#include <cstring>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int t, n;
bool ans;
char phone_number[10001][11];

struct trie {
	trie* next[10];
	bool terminal;

	trie() : terminal(false) {
		memset(next, 0, sizeof(next));
	}
	~trie() {
		for (int i = 0; i < 10; i++) {
			if (next[i]) delete next[i];
		}
	}
	int ctoi(char c) {
		return c - '0';
	}

	void insert(const char* key) {
		if (*key == '\0') terminal = true;
		else {
			int cur = ctoi(*key);
			if (next[cur] == NULL)
				next[cur] = new trie;
			next[cur]->insert(key + 1);
		}
	}
	bool find(const char* key) {
		if (*key == '\0') return false;
		if (terminal) return true;
		int cur = ctoi(*key);
		return next[cur]->find(key + 1);
	}
};

int main() 
{
	io;
	cin >> t;
	while (t--) {
		cin >> n;
		trie *root = new trie;
		for (int i = 0; i < n; i++) {
			cin >> phone_number[i];
			root->insert(phone_number[i]);
		}

		ans = false;
		for (int i = 0; i < n; i++) {
			if (root->find(phone_number[i])) {
				ans = true;
				break;
			}
		}
		cout << (ans ? "NO\n" : "YES\n");
	}
	return 0;
}