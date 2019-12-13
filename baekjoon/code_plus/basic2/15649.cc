/*
[BOJ] 15649. N과 M
*/
#include <cstdio>
using namespace std;
int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=1;i<=n;i++){
        printf("%d ", i);
        for(int j=1;j<m;j++){
            printf("%d", i);
        }
        printf("\n");
    }
    return 0;
}