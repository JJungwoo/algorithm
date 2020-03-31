/*
[boj] 17135. 캐슬 디펜스
각각의 턴마다 궁수는 하나의 적을 공격하고, 모든 궁수는 동시에 공격한다
같은 적이 여러 궁수에게 공격당할수 있고 궁수가 공격하는 적은 거리가 D이하인 적중에
가장 가까운 적이고, 그러한 적이 여럿일 경우 가장 왼쪽에 적을 공격한다.
궁수의 공격이 끝나고 적이 이동한다.
d = |n - i| + |k - j|

해결 방법
1. dfs로 경로 찾아서 공격 
2. 2중 포문으로 하나씩 다 거리 체크해서 공격
3. 공격 대상들 리스트만들어서 정렬한다음 작은 값부터 공격

*/
#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int n,m,d,ans;
int map[16][16], tmp_map[16][16];
vector<int> hunters;
inline int cal_dis(int x1, int y1, int x2, int y2){
	return abs(x1-x2) + abs(y1-y2);
}
void copy_map(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			tmp_map[i][j] = map[i][j];
		}
	}
}
void print_map(){
	cout<<"print_map\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<tmp_map[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void solve(int cur, int cnt){
	if(cnt == 3){
		//cout<<"debug:"<<hunters[0]<<","<<hunters[1]<<","<<hunters[2]<<"\n";
		int sum = 0;
		copy_map();
		for(int i=n;i>0;i--){
			vector<pair<int, int> > kill;
			for(int j=0;j<3;j++){
				int tj = hunters[j], value = 16*16;
				int dx = 0, dy = 16;
				for(int z=1;z<=d;z++){
					for(int y=0;y<m;y++){
						if(i-z < 0) continue;
						int tmp = cal_dis(i, tj, i-z, y);
						if(tmp <= d && tmp_map[i-z][y] == 1){
							//cout<<i<<","<<tj<<" <> "<<i-z<<","<<y<<"="<<tmp<<"\n";
							if(tmp <= value){
								if(dy > y){
									value = tmp;
									dx = i-z, dy = y;
								}

							}
						}
					}
				}
				if(value != 16*16){
					kill.push_back(make_pair(dx, dy));
				}
			}
			int size = kill.size();
			for(int j=0;j<size;j++){
				int x = kill[j].first, y = kill[j].second;
				if(tmp_map[x][y] != 0) sum++;
				tmp_map[x][y] = 0;
			}
			//print_map();
		}
		if(ans < sum){
			//cout<<"sum:"<<sum<<"\n";
			ans = sum;
		}
		return;
	}

	for(int i=cur;i<m;i++){
		hunters.push_back(i);
		solve(i + 1, cnt + 1);
		hunters.pop_back();
	}
}
int main()
{
	io;
	cin>>n>>m>>d;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>map[i][j];
		}
	}
	solve(0, 0);
	cout<<ans<<"\n";
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, m, d, ans;
int map[16][16];
bool visited[16];
vector<int> archer;

struct castle{
    int x, y, z;
    bool operator < (const castle &t) const {
        if(z == t.z) return y > t.y;
        else return z > t.z;
    }
};

void move_monster() {
	for (int i = n-1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			if (map[i][j] == 1 && i == n - 1) {
				map[i][j] = 0;
			}
			else if(map[i][j] == 1) {
				swap(map[i][j], map[i + 1][j]);
			}
		}
	}
}

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
}

void hunting_monster(int pos) {

}

void dfs(int cnt) {
	if (cnt == 3) {
		for (int i = 0; i < n; i++) {
			vector<pair<int, int> > killed;
			for (int j = 0; j < archer.size(); j++) {

			}
		}
		ans = max(ans, cnt);
		return;
	}
	for (int i = 0; i < m; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		archer.push_back(i);
		dfs(cnt + 1);
		archer.pop_back();
		visited[i] = false;
	}
}

int main() 
{
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	dfs(0);
	cout << ans << "\n";
	return 0;
}
*/