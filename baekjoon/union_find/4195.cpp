/*
[boj] 4195. 친구 네트워크
계속 런타임 에러 뜸;; 왜그런거지.. 하아..
중간에 런타임에러..
*/

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int parent[200011], usize[200011];
void init(int n) {
	for (int i = 0; i < n; i++) {
		parent[i] = i;
		usize[i] = 1;
	}
}

int find(int p) {
	if (parent[p] == p) return p;
	else parent[p] = find(parent[p]);
}

void uni(int p, int q) {
	p = find(p);
	q = find(q);
	if (q == p) return;
	if (usize[q] < usize[p]) {
		parent[q] = p;
		usize[p] += usize[q];
	}
	else {
		parent[p] = q;
		usize[q] += usize[p];
	}
}

int main()
{
	io;
	int t; 
	cin >> t;
	while (t--) {
		map<string, int> m;
		int cnt = 0;
		int f; cin >> f;
		init(f * 2);
		for (int i = 0; i < f; i++) {
			string a, b;
			cin >> a >> b;
			if (m.count(a) == 0) {
				m.insert(make_pair(a, cnt++));
			}
			if (m.count(b) == 0) {
				m.insert(make_pair(b, cnt++));
			}
			uni(m[a], m[b]);
			int tmp = find(m[a]);
			//cout << tmp << ":" << usize[tmp] <<":"<<usize[m[a]]<<":"<<parent[m[a]]<< "\n";
			//cout << usize[parent[m[a]]] << "\n";
			cout << usize[tmp] << "\n";
		}
	}
	return 0;
}

/*

// c++ stl map 사용법

	#include <map>

	map<string, int> m;

	m.insert(make_pair("test0", 0));
	m.insert(make_pair("test1", 1));
	m.insert(make_pair("test2", 2));
	m.insert(make_pair("test3", 3));

	for (auto it = m.begin(); it != m.end(); it++) {
		cout << it->first << "," << it->second << "\n";
	}

	cout << m.find("test0")->first << m.find("test0")->second << "\n";
	//cout << m.find("test5")->first << m.find("test5")->second << "\n";
	auto it = m.find("test5");
	if (it == m.end()) cout << "fail\n";
	else cout << it->first << "," << it->second << "\n";

*/