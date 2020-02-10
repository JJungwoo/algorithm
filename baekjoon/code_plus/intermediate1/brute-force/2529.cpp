/*
[BOJ] 2529. 부등호
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int k, max_ans, min_ans = 987654321;
char sign[11];
int number[11];
int visited[11];

void solve(int cnt){
    if(cnt == k+1){
        int ncnt = 0;
        bool chk = true;
        for(int i=0;i<k;i++){
            if(sign[i] == '<'){
                if(number[ncnt] > number[ncnt+1]){
                    chk = false;
                    break;
                }
            }else{
                if(number[ncnt] < number[ncnt+1]){
                    chk = false;
                    break;
                }
            }
            ncnt++;
        }
        if(chk){
            int result = 0;
            for(int i=k;i>=0;i--){
                result += (number[i] * pow(10, i));
                cout<<result<<","<<number[i]<<","<<pow(10,i)<<"\n";
            }
            cout<<"res: "<<result<<"\n";
            max_ans = max(max_ans, result);
            min_ans = min(min_ans, result);
        }
    }

    for(int i=0;i<10;i++){
        if(!visited[i]){
            visited[i] = true;
            number[cnt] = i;
            solve(cnt+1);
            visited[i] = false;
        }
    }
}

int main()
{
    io;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>sign[i];
    }

    solve(1);
    cout<<max_ans<<"\n";
    cout<<min_ans<<"\n";

    return 0;
}