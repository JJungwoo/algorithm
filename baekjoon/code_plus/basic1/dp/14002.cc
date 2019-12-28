/*
[BOJ] 14002. 가장 긴 증가하는 부분 수열 4
*/

/*
dp 방식 dp cache에 현재 위치보다 이전 위치의 값이 작다면 1씩 증가시켜서
가장 최대가 되는 수열의 길이를 출력한다.
*/
#include <iostream>
#include <vector>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n;
int seq[1001], dp[1001];
vector<int> ans;
int main()
{
    //io;
    printf("!@#!\n");
    /*cin>>n;
    for(int i=1;i<=n;i++) 
        cin>>seq[i];
    dp[1] = seq[1];
    for(int i=1;i<=n;i++){
        dp[i] = 1;
        for(int j=1;j<i;j++){
            if(seq[i] > seq[j] && dp[i] < dp[j]+1){
                dp[i] = dp[j]+1;
                ans.push_back(j);
            }
        }
    }
    */
    cout<<dp[n]<<"\n";
    return 0;
}


/*
#include <iostream>
using namespace std;
int main()
{
    int A[1000] = { 0, };
    int lis[1000] = { 0, };
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    int i = 1, j = 0;
    lis[0] = A[0];
    while (i < n) {
        if (A[i] > lis[j]) {
            lis[j + 1] = A[i];
            j++;
        }
        else {
            int lo = 0, hi = j;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (lis[mid] < A[i])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
            lis[lo] = A[i];
        }
        i++;
    }
    cout << j+1 << '\n';
    for(int z=0;z<=j;z++) cout<<lis[z]<<" ";
    return 0;
}
*/