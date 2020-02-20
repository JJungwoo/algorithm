/*
[BOJ] 2529. 부등호
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

long long k, max_ans, min_ans = 9e9;
char sign[11];
int number[11];
int visited[11];

void solve(int cnt){
    if(cnt == k+1){
        int ncnt = 0;
        bool chk = true;
        for(int i=0;i<k;i++){
            if(sign[i] == '<'){
                if(number[i] > number[i+1]){
                    return;
                }
            }else{
                if(number[i] < number[i+1]){
                    return;
                }
            }
            //cout<<ncnt<<": "<<number[i]<<" "<<sign[i]<<" "<<number[i+1]<<"\n";
            ncnt++;
        }

        long long result = 0;
        for(int i=k, j=0;i>=0;i--,j++){
            result += (number[j] * pow(10, i));
            //cout<<result<<","<<number[i]<<","<<pow(10,i)<<"\n";
        }
        //cout<<"res: "<<result<<"\n";
        max_ans = max_ans < result ? result : max_ans;
        min_ans = min_ans > result ? result : min_ans;
        return;
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

    solve(0);
    string max_str = to_string(max_ans);
    string min_str = to_string(min_ans);

    cout<<max_str<<"\n";
    int dif = max_str.size() - min_str.size();
    for(int i=0;i<dif;i++){
        cout<<"0";
    }
    cout<<min_str<<"\n";

    return 0;
}