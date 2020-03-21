/*
[boj] 16922. 로마 숫자 만들기
 I, V, X, L  = 1, 5, 10, 50
 ex) 
 XXXV = 35 (10+10+10+5)
 IXI = 12 (10+1+1)
 // 
 solve 함수에 cur이 들어갈때와 안들어갈때 시간 초과 차이..
 언제 cur 인자값을 넣어줘야 할까? 기준??
 = cur 인자값은 선택할 조합 경우의 수에서 중복을 없애기 위해 사용된다.
 ex) 0 1 0 
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, ans;
bool visited[1001];
int values[] = { 1,5,10,50 };

void solve(int cur, int cnt, int sum) {		
	if (cnt == n) {						// 카운팅 결과값 계산 
		if (visited[sum]) return;
		visited[sum] = true;
		cout << "="<< sum<< "\n";
		ans++;
		return;
	}

	//for (int i = 0; i < 4; i++) {	// 시간 초과
	for (int i = cur; i < 4; i++) {		// 조합(경우의 수) 선택
		int tmp = sum + values[i];
		cout <<"["<<i<<"]"<< "tmp: " << sum << " + " << values[i] << "\n";
		solve(i, cnt + 1, tmp);			
	}
}

int main()
{
	io;
	cin >> n;
	solve(0, 0, 0);
	cout << ans << "\n";
	return 0;
}

