/*
[boj] 10815. 숫자 카드
*/
/*
// 이분 탐색 풀이 find 함수 대신에 STL의 binary search(arr.begin(), arr.end()) 함수도 가능

#include <iostream>
#include <algorithm>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m;
vector<int> arr;
bool find(int value) {
	int left = 0, right = n - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (value == arr[mid])
			return true;
		else if (value > arr[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return false;
}
int main()
{
	io;
	cin >> n;
	arr.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		cout << find(tmp) << " ";
	}
	cout << "\n";
	return 0;
}
*/
/*

// set 풀이

#include <iostream>
#include <set>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, m;
set<int> s;
int main()
{
	io;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		s.insert(tmp);
	}
	
	cin >> m;
	for (int i = 0; i < m; i++) {
		int tmp; cin >> tmp;
		if (s.find(tmp) == s.end()) cout<<"0 ";
		else cout << "1 ";
	}
	cout << "\n";

	return 0;
}
*/