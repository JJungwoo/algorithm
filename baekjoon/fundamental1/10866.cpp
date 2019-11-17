/*
[BOJ] 10866. µ¦
https://www.acmicpc.net/problem/10866
*/
/*
#include <cstdio>
#include <string.h>
#include <deque>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	deque<int> dq;

	for (int i = 0; i < n; i++) {
		char tmp[20] = { '\0' };
		scanf("%s", &tmp);
		if (!strcmp("push_front", tmp)) {
			int val;
			scanf("%d", &val);
			dq.push_front(val);
		}
		else if (!strcmp("push_back", tmp)) {
			int val;
			scanf("%d", &val);
			dq.push_back(val);
		}
		else if (!strcmp("pop_front", tmp)) {
			if (!dq.empty()) {
				printf("%d\n", dq.front());
				dq.pop_front();
			}
			else printf("-1\n");
		}
		else if (!strcmp("pop_back", tmp)) {
			if (!dq.empty()) {
				printf("%d\n", dq.back());
				dq.pop_back();
			}
			else printf("-1\n");
		}
		else if (!strcmp("size", tmp)) printf("%d\n", dq.size());
		else if (!strcmp("empty", tmp)) printf("%d\n", dq.empty());
		else if (!strcmp("front", tmp)) {
			if (!dq.empty()) printf("%d\n", dq.front());
			else printf("-1\n");
		}
		else if (!strcmp("back", tmp)) {
			if (!dq.empty()) printf("%d\n", dq.back());
			else printf("-1\n");
		}
	}
	return 0;
}
*/

/*
queue + stack

#include <cstdio>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main() {
	int n, head = 0, tail = 0, size = 0;
	scanf("%d", &n);
	queue<int> front_queue;
	stack<int> back_stack;

	for (int i = 0; i < n; i++) {
		char *tmp = NULL;
		scanf("%s", &tmp);
		if (strcmp("push_front", tmp)) {
			int val;
			scanf("%d", &val);
			front_queue.push(val);
		}
		else if (strcmp("push_back", tmp)) {
			int val;
			scanf("%d", &val);
			back_stack.push(val);
		}
		else if (strcmp("pop_front", tmp)) {
			if (!front_queue.empty()) {
				printf("%d\n", front_queue.front());
				front_queue.pop();
			}
			else if (!back_stack.empty()) {
				printf("%d\n", back_stack.top);
			}
		}
		else if (strcmp("pop_back", tmp)) {

		}
		else if (strcmp("size", tmp)) {

		}
		else if (strcmp("empty", tmp)) {

		}
		else if (strcmp("front", tmp)) {

		}
		else if (strcmp("back", tmp)) {

		}
	}

	return 0;
}

*/