/*
[boj] 5430. AC
https://www.acmicpc.net/problem/5430
*/

#include <iostream>
#include <string>
#include <deque>
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main() 
{
    io;
    int T, N;  // 1 정방향
    string cmd, input;
    cin >> T;
    while(T--) {
        int dir = 1;
        cin >> cmd;
        cin >> N;
        deque<int> nums;
        bool check = true;
        cin >> input;

        int cur = input.length() - 2;
        int prev = input.length() - 1;
        while(cur != 0) {
            if(input.at(cur) == ',') {
                nums.push_front(stoi(input.substr(cur + 1, prev - cur)));
                prev = cur;
                cur--;
            }else{
                cur--;
            }
        }
        if(prev != 1) {
            nums.push_front(stoi(input.substr(1, prev)));
        }
        /*
        // 하나씩 처리하면 시간초과 발생한다.
        for(int i=0;i<input.length();i++) { cur+1, prev - cur
            int idx = i;
            while(input[idx] >= '0' && input[idx] <= '9') {
                idx++;
            }
            int tmp = atoi(input.substr(i, idx).c_str());
            if(tmp == 0) continue;
            nums.push_back(tmp);
            i = idx;
        }
        */


        for(auto it : cmd) {
            if('R' == it) {
                dir ^= 1;
            }
            else if('D' == it) {
                if(nums.size() == 0) {
                    check = false;
                    break;
                }else {
                    if(dir)
                        nums.pop_front();
                    else
                        nums.pop_back();
                }
            }
        }

        if(check) {
            if(dir){
                cout<<"[";
                while(!nums.empty()) {
                    cout<<nums.front();
                    nums.pop_front();
                    if(nums.size() > 0)
                        cout<<",";
                }
                cout<<"]\n";
            }else{
                cout<<"[";
                while(!nums.empty()) {
                    cout<<nums.back();
                    nums.pop_back();
                    if(nums.size() > 0)
                        cout<<",";
                }
                cout<<"]\n";
            }
        }else cout<<"error\n";
    }
    return 0;
}