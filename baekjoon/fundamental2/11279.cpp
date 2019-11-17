/*
[BOJ] 11279. ÃÖ´ë Èü
https://www.acmicpc.net/problem/11279

#include <cstdio>
#include <vector>
using namespace std;

#define swap(a,b){int tmp; tmp = a; a = b; b = tmp;}

void push_heap(vector<int>& heap, int newValue) {
	heap.push_back(newValue);
	int idx = heap.size() - 1;
	while (idx > 0 && heap[(idx - 1) / 2] < heap[idx]) {
		swap(heap[idx], heap[(idx - 1) / 2]);
		idx = (idx - 1) / 2;
	}
}

int pop_heap(vector<int>& heap) {
	if (heap.empty() == 1)
		return 0;
	int value = heap[0];
	heap[0] = heap.size();
	heap.pop_back();
	int here = 0;
	while (true) {
		int left = here * 2 + 1, right = here * 2 + 2;
		if (left >= heap.size()) break;
		int next = here;
		if (heap[next] < heap[left])
			next = left;
		if (right < heap.size() && heap[next] < heap[right])
			next = right;
		if (next == here) break;
		swap(heap[here], heap[next]);
		here = next;
	}
	return value;
}

int main()
{
	int n;
	vector<int> heap;
	scanf("%d", &n);
	while (n--) {
		int val;
		scanf("%d", &val);
		if (val == 0)
			printf("%d\n", pop_heap(heap));
		else
			push_heap(heap, val);
	}
	return 0;
}
*/
/*
#include <cstdio>
using namespace std;

int size;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node root = { 0, NULL, NULL };

void create_and_append(int val) {
	if (root.data == 0)
		root = { val, NULL, NULL };
	else {

	}
}

int main()
{
	int n;
	int arr[100001] = { 0, };
	scanf("%d", &n);
	while (n--) {
		long val;
		scanf("%ld", &val);
		if (val == 0) {
			if (size == 0)
				printf("0\n");
			else
				;
		}
		else {

		}
	}
	
	return 0;
}
*/