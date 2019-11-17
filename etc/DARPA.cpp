/*
algospot DARPA Grand Challenge 
*/
/*
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double C, N, M, cnt;
double cameras[201];

int decision(int mid) {
	double first = cameras[0];
	cnt = 1;
	for (int i = 0; i < M; i++) {
		
		if (cameras[i] - first >= mid) {
			first = cameras[i];
			cnt++;
			if (cnt >= N)
				return true;
		}
	}
	return false;
}

double optimize() {
	double lo = 0, hi = 241;
	while (lo + 1 < hi) {
		double mid = (lo + hi) / 2.0;
		if (decision(mid)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return lo;
}

int main()
{
	//cout.setf(ios::fixed);
	//cout.precision(2);
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N >> M;
		for (int j = 0; j < M; j++)
			cin >> cameras[j];
		cout << fixed << setprecision(2);
		cout << floor(optimize()) << endl;
	}
	return 0;
}
*/

/*

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;
double C, N, M, cnt;
double cameras[201];

int decision(const vector<double>& location, int mid) {
	double limit = -1;
	int installed = 0;
	for (int i = 0; i < location.size(); i++) {
		if (limit <= location[i]) {
			++installed;
			limit = location[i] + mid;
		}
	}
	return installed >= N;
}

double optimize(const vector<double>& location) {
	double lo = 0, hi = 241;
	for (int i = 0; i < 100; i++) {
		double mid = (lo + hi) / 2;
		if (decision(location, mid)) 
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}


int main()
{
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> N >> M;
		vector<double> location;
		for (int j = 0; j < M; j++) {
			double value;
			cin >> value;
			location.push_back(value);
		}
		cout << fixed << setprecision(2);
		cout << floor(optimize(location)) << endl;
	}
	return 0;
}

*/