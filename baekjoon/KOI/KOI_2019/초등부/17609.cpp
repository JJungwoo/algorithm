/*
[boj] 17609. 회문
https://www.acmicpc.net/problem/17609
*/

#include <iostream>
#include <string>
#include <vector>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int T, ans;
string msg[30];
int check_palin(string tmp){
    int lo = 0, hi = tmp.size()-1;
    int check_cnt = 0, remove_cnt = 0, fail_cnt = 0;
    while(lo <= hi){
        //cout<<tmp[lo]<<" == "<<tmp[hi]<<"\n";
        //cout<<"cnt: "<<check_cnt<<" = lo: "<<lo<<" hi: "<<hi<<"\n";
        if(tmp[lo] == tmp[hi]){
            //cout<<tmp[lo]<<" <> "<<tmp[hi]<<"\n";
            check_cnt++;
            lo++;
            hi--;
        }else if(remove_cnt < 2 && tmp[lo] == tmp[hi-1]){
            hi--;
            remove_cnt++;
        }else if(remove_cnt < 2 && tmp[lo+1] == tmp[hi]){
            lo++;
            remove_cnt++;
        }else{
            fail_cnt++;
            lo++;
            hi--; 
        }

        if(remove_cnt >= 2 || fail_cnt > 1){
            return 2;
        }
    }
    //cout<<remove_cnt<<"\n";
    //cout<<check_cnt<<","<<tmp.size()<<"\n";
    if(check_cnt > tmp.size()/2-1 && remove_cnt == 1)
        return 1;
    else if(check_cnt > tmp.size()/2-1)
        return 0;
    else 
        return 2;
}
int main()
{
	io;
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>msg[i];
        cout<<check_palin(msg[i])<<"\n";
    }
	return 0;
}
