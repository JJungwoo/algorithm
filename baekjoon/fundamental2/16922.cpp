/*
[boj] 16922. �θ� ���� �����
 I, V, X, L  = 1, 5, 10, 50
 ex) 
 XXXV = 35 (10+10+10+5)
 IXI = 12 (10+1+1)
 // 
 solve �Լ��� cur�� ������ �ȵ��� �ð� �ʰ� ����..
 ���� cur ���ڰ��� �־���� �ұ�? ����??
 = cur ���ڰ��� ������ ���� ����� ������ �ߺ��� ���ֱ� ���� ���ȴ�.
 ex) 0 1 0 
*/

#include <iostream>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int n, ans;
bool visited[1001];
int values[] = { 1,5,10,50 };

void solve(int cur, int cnt, int sum) {		
	if (cnt == n) {						// ī���� ����� ��� 
		if (visited[sum]) return;
		visited[sum] = true;
		cout << "="<< sum<< "\n";
		ans++;
		return;
	}

	//for (int i = 0; i < 4; i++) {	// �ð� �ʰ�
	for (int i = cur; i < 4; i++) {		// ����(����� ��) ����
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

