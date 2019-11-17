/*
baekjoon 2740¹ø Çà·Ä °ö¼À
*/
/*
#include <iostream>
using namespace std;
int main()
{
	int N, M, K;
	int A[101][101], B[101][101], C[101][101];

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> A[i][j];

	cin >> M >> K;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < K; j++)
			cin >> B[i][j];

	for (int i = 0; i < N; i++)
		for (int j = 0; j <K; j++)
			for (int z = 0; z < M; z++) 
				C[i][j] += (A[i][z] * B[z][j]);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
			cout << C[i][j] << " ";
		cout << endl;
	}
	return 0;
}
*/

