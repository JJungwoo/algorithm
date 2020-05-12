#include <string>
#include <vector>
#include <iostream>
using namespace std;

// Two pointer technique based solution to find 
// if there is a pair in A[0..N-1] with a given sum. 
bool isPairSum(int A[10], int N, int X)
{
	// represents first pointer 
	int i = 0;

	// represents second pointer 
	int j = N - 1;

	while (i < j) {

		// If we find a pair 
		if (A[i] + A[j] == X) {
			for (int i = 0; i < N; i++) {
				cout << A[i] << " ";
			}
			cout << "\n";
			cout << "X = " << X << "\n";
			cout << "i = " << i << "\n";
			cout << "j = " << j << "\n";
			return true;
		}
			

		// If sum of elements at current 
		// pointers is less, we move towards 
		// higher values by doing i++ 
		else if (A[i] + A[j] < X)
			i++;

		// If sum of elements at current 
		// pointers is more, we move towards 
		// lower values by doing j-- 
		else
			j--;
	}
	
	return false;
}

int main()
{
	int arr[10] = { 10, 20, 35, 50, 75, 80 };

	
	isPairSum(arr, 6, 70);


	return 0;
}