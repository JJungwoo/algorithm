/*
[boj] 1644. 소수의 연속합 
https://www.acmicpc.net/problem/1644
*/

#include <iostream>
#include <cmath>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
#define MAX 4000000 
int N, prime_num[MAX+1], answer;
void find_prime() {
    int size = sqrt(N);
    prime_num[0] = true;
    prime_num[1] = true;
    for(int i=2;i<=size;i++) {
        for(int j=i*i;j<=N;j+=i) {
            prime_num[j] = true;
        }
    }
}
int main() 
{
    io;
    cin >> N;
    find_prime();
    int left = 0, right = 1, sum = 0;
    while(left < right && MAX >= right) {
        if(sum >= N) {
            if(prime_num[left] == false) {
                sum -= left;
                if(sum == N) answer++;
            }
            left++;
        }else if(right > N) 
            break;
        else {
            if(prime_num[right] == false) {
                sum += right;
                if(sum == N) answer++;
            }
            right++;
        }
         
    }
    cout<<answer<<"\n";
    return 0;
}