
/*
#include <iostream>
using namespace std;
#define SIZE 21
int n, s, ans;
int arr[SIZE], ch_arr[SIZE];
void find(int idx, int cnt, int sum)
{
	if (n == 1) {
		sum += arr[idx];
	}
	if (cnt > n) {
		return;
	}
	if (sum == s) {
		ans++;
		return;
	}

	if (!ch_arr[idx])
	{
		ch_arr[idx] = 1;
		find(idx, cnt + 1, sum + arr[idx]);
		ch_arr[idx] = 0;
	}
	find(idx + 1, cnt + 1, sum + arr[idx]);
}
int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	
	find(0, 0, 0);
	
	cout << ans << endl;

	return 0;
}
*/

/*
#include <iostream>

using namespace std;

int main()
{
	int C, N, M;
	float arr[201] = { 0, };

	cin >> C;
	for (int t = 0; t < C; t++) {
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			cin >> arr[i];
		}
	}

	return 0;
}
*/


/*
// 이분법과 최적화 문제 풀이 모음.
// 2019.06.20 
*/

// backjoon 2512번 예산.
/*
#include <iostream>

using namespace std;

int main()
{
	int N, M, left = 0, mid ,right, sum;
	int arr[10001] = { 0, };
	
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> M;

	right = M;

	while (right >= left) {
		sum = 0;
		mid = (left + right) / 2;

		for(int i=0;i<N;i++) {
			if (mid < arr[i])
				sum += mid;
			else
				sum += arr[i];
			
		}

		if (sum <= M) {
			sum = mid;
			right = mid + 1;
		}
		else
			left = mid - 1;
	}

	cout << sum << endl;


	return 0;
}
*/

/*
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int N, M, ans = 0, sum = 0, left = 0, right = 0;
	int arr[10001] = { 0, };
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
		ans = max(ans, arr[i]);
	}
	cin >> M;
	right = M;

	if (sum <= M) {
		cout << ans << endl;
		return 0;
	}

	while (right >= left) {
		int mid = (left +  right) / 2;
		sum = 0;
		for (int i = 0; i < N; i++)	{
			sum += min(arr[i], mid);	
		}
		if (sum > M) {	
			right = mid - 1;	
		}
		else {
			left = mid + 1;
			ans = mid;
		}
	}
	cout << ans << endl;
	
	return 0;
}
*/



// backjoon 2805번 나무 자르기.


// backjoon 2343번 기타 레슨


/*
// backjoon 2110번 공유기.

#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, c;
	int arr[200001] = { 0, };
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int left = 1; // 가능한 최소 거리
	int right = arr[n - 1] - arr[0]; // 가능한 최대 거리
	int d = 0;
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2; // 기준
		int start = arr[0];
		int cnt = 1;

		// 간격(d) 를 기준으로 공유기 설치
		for (int i = 1; i < n; i++) {
			d = arr[i] - start;
			if (mid <= d) {
				++cnt;
				start = arr[i];
			}
		}
		
		if (cnt >= c) {
			// 공유기의 수를 줄이자 => 간격 넓히기
			ans = mid;
			left = mid + 1;
		}
		else {
			// 공유기가 더 설치되어야한다. => 간격 좁히기
			right = mid - 1;
		}
	}

	cout << ans;

	return 0;
}
*/

/*
// [backjoon] 17179번.  케이크 자르기

#include <iostream>
#include <algorithm>
using namespace std;

int N, M, L, ans;
int n_arr[1001];

int decision(int d) {
	int st = n_arr[0];
	int cnt = 0;
	for (int i = 1; i < M + 1; i++) {
		if ((n_arr[i] - st) >= d)
		{
			cnt++;
			st = n_arr[i];
		}
	}
	return cnt;
}

void optimize(int cut) {
	int left, right, cnt = 0;
	left = 1;	// 케이크 가장 앞
	right = L;	// 케이크 길이 즉, 케이크 끝 길이
	while (left <= right) {
		int mid = (left + right) / 2;
		if (cut <= (cnt = decision(mid))) {
			left = mid + 1;
			if (cut == cnt)
				ans = max(ans, mid);
		}
		else
			right = mid - 1;
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int cut;
	cin >> N >> M >> L;
	for (int i = 0; i < M; i++) 
		cin >> n_arr[i];
	n_arr[M] = L;
	for (int i = 0; i < N; i++) {
		cin >> cut;
		optimize(cut + 1);
	}
		
	return 0;
}
*/

/*
// backjoon 11561번 징검다리
#include <iostream>
#include <cmath>
using namespace std;
typedef unsigned long long LL;
LL decision(LL n) {
	return (n * (n + 1)) / 2;
}
void optimize(LL val) {
	LL left = 1, right = sqrt(val+1)*2, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (val < decision(mid)) {
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << right << endl;
}
int main()
{
	ios::sync_with_stdio(false);
	LL T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		if (N == 1 || N == 2)
			cout << 1 << endl;
		else
			optimize(N);
	}
	return 0;
}
*/




// backjoon 3090번. 차이를 최소로

/*

#include <iostream>
using namespace std;

int decision()
{

}

void optimize()
{

}

int main()
{

	return 0;
}*/


/*
// [backjoon] 17179번.  케이크 자르기

#include <iostream>
using namespace std;

int N, M, L;
int n_arr[1011];

int decision(int d) {
	int st = n_arr[0];
	int cnt = 0;
	for (int i = 1; i < M + 1; i++) {
		if ((n_arr[i] - st) >= d)
		{
			cnt++;
			st = n_arr[i];
		}
	}
	return cnt;
}

void optimize(int cut) {
	int left, right;
	left = 1;	// 케이크 가장 앞
	right = L+1;	// 케이크 길이 즉, 케이크 끝 길이
	while (left <= right) {
		int mid = (left + right) / 2;
		if (cut <= decision(mid)) {
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << left - 1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	int cut;
	cin >> N >> M >> L;
	for (int i = 0; i < M; i++)
		cin >> n_arr[i];
	n_arr[M] = L;
	for (int i = 0; i < N; i++) {
		cin >> cut;
		optimize(cut);
	}

	return 0;
}
*/

/*
// backjoon 1939번 중량 제한

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector< pair<int, int> > arr[100001];
typedef unsigned long long LL;
int N, M, s, e;
bool decision(int val)
{
	bool visited[100001] = { false, };
	queue<int> q;
	visited[s] = true;
	q.push(s);

	while (!q.empty()) 
	{
		int cur = q.front();
		q.pop();

		if (cur == e)
			return true;

		for (int i = 0; i < arr[cur].size(); i++)
		{
			int next = arr[cur][i].first;
			int nextval = arr[cur][i].second;

			if (!visited[next] && val <= nextval)	// ?? val >= nextval 이렇게 되야하는거 아닌가??
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
	
	return false;
}

LL optimize()
{
	LL lo = 0, hi = (LL)1e9 + 1;
	while (lo + 1 < hi) {
		LL mid = (lo + hi) / 2;
		if (decision(mid)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return lo;		// hi가 답이 되야하는거 아닌가??
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
		arr[b].push_back(make_pair(a, c));
	}

	cin >> s >> e;
	cout << optimize() << endl;

	return 0;
}
*/

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> adj;
int S,E;

bool decision(int w) {
vector<bool> discovered(adj.size(), false);
queue<int> q;
q.push(S);
discovered[S]=true;
while(!q.empty()) {
int here=q.front();
q.pop();
if(here==E)
return true;
for(auto &there:adj[here]) {
if(discovered[there.first])
continue;
if(there.second<w)
continue;
q.push(there.first);
discovered[there.first]=true;
}
}
return false;
}

long long optimize() {
long long lo=0, hi=(long long)(1e9)+1;
while(lo+1<hi){
long long mid=(lo+hi)/2;
if(decision(mid)) {
lo=mid;
} else {
hi=mid;
}
}
return lo;
}
int main() {
int N, M;
cin>>N>>M;
adj.resize(N);
for(int i=0; i<M; ++i){
int A,B,C;
cin>>A>>B>>C;
A--; B--;
adj[A].emplace_back(B, C);
adj[B].emplace_back(A, C);
}
cin>>S>>E;
S--; E--;

long long ans=optimize();
cout<<ans;

//std::cout << "Hello, World!" << std::endl;
return 0;
}
*/

/*
#include <iostream>
using namespace std;
typedef unsigned long long LL;
int N, T;
int arr[100001];
int ans[100001];

bool decision()
{
	return false;
}

void optimize()
{
	LL lo = 0, hi = 1e10 + 1;
	
}

int main()
{
	cin >> N >> T;
	for (int i = 0; i < T; i++)
		cin >> arr[i];
	
	cout << 1e9 << endl;

	return 0;
}

*/


/*

// algospot
#include <iostream>
using namespace std;
typedef unsigned long long LL;
LL N, M;
int decision(LL games, LL win)
{
	return (win * 100) / games;
}

int optimize()
{
	if (decision(N, M) == decision(N + 2e10, M + 2e10))
		return -1;
	LL lo = 0, hi = 2e10 + 1;	// lo : true, hi : false
	while (lo + 1 < hi) {
		LL mid = (lo + hi) / 2;
		if (decision(N, M) == decision(N + mid, M + mid))
			lo = mid;
		else 
			hi = mid;
	}
	return hi;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M;
		cout << optimize() << endl;
	}
	return 0;
}

*/


/*
// algospot 전세금 균등상환

#include <iostream>
using namespace std;

double

double payment(double amount, int duration, double rates)
{
	double lo = 0, hi = amount * (1.0 + (rates / 12.0) / 100.0);
	while (lo + 1 < hi) {
		double mid = (lo + hi) / 2.0;
		if()
	}
}

int main()
{

	return 0;
}

*/

/*
#include <iostream>
using namespace std;
typedef unsigned long long LL;

LL arr[100001] , tarr[100001];
LL N, T;

bool decision(LL val)
{
	while (val) {
		
	
		val--;
	}
	return false;
}

void optimize()
{
	LL lo = 0, hi = 1e9 + 1;
	while (lo + 1 > hi)
	{
		LL mid = (lo + hi) / 2;
		if (decision(mid)) {
			for (int i = 0; i < N; i++)
				tarr[i] = arr[i];
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
}

int main()
{
	cin >> N >> T;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	optimize();
	for (int i = 0; i < N; i++)
		cout << tarr[i] << " ";

	return 0;
}
*/

