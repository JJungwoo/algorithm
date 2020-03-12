/*
[boj] 16938. 캠프 준비
캠프에 사용할 문제는 두 문제 이상이어야 한다
문제 난이도의 합은 L보다 크거나 같고, R보다 작거나 같아야 한다.
가장 어려운 문제와 가장 쉬운 문제의 난이도 차이는 X보다 크거나 같아야 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int n, l, r, x, ans;
int problem[1000001];
bool visited[1000001];
vector<int> plist;
void solve(int cnt, int sum) {
	if (cnt >= 2) {
		if (sum >= l && sum < r) {
			sort(plist.begin(), plist.end());
			cout<<"size:"<<plist.size()<<" , "<<cnt<<","<<plist[0]<< ", " << plist[plist.size()-1] <<" x:"<<x<< "\n";
			//if (plist.end() - plist.begin() >= x) {
			if (plist[plist.size()-1] - plist[0] >= x) {
				ans++;
			}
		}
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		plist.push_back(problem[i]);
		solve(cnt+1, sum + problem[i]);
		plist.pop_back();
		visited[i] = false;
	}
}
int main()
{
	io;
	cin >> n >> l >> r >> x;
	for (int i = 0; i < n; i++) {
		cin >> problem[i];
	}
	solve(0, 0);
	cout << ans << "\n";
	return 0;
}