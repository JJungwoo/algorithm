/*
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int n, answer = 1;
string msg;
int main()
{
    cin>>n;
    cin>>msg;
    while(answer <= n){
        bool ch = true;
        vector<string> v;
        for(int i=0;i<n;i++){
            if(i + answer <= n){
                v.push_back(msg.substr(i, answer));
            }
        }

        for(int i=0;i<v.size()-1;i++){
            string tmp = v[i];
            for(int j=i+1;j<v.size();j++){
                if(tmp == v[j]){
                    ch = false;
                    break;
                }
            }
            if(!ch) break;
        }
        if(ch) break;
        answer++;
    }
    cout<<answer<<"\n";
    return 0;
}
*/



#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;
// problem
// 농장에는 집번호가 없어서 자신의 위치를 알아 내기 어려움
// 각 농장에는 도로 옆 우편함이 있어 
// 메일 박스가 근방에 있으면 그는 자기가 어디있는지 알아 낼수 있음
// 각각의 메일함은 a~z로 색깔을 나타냄
// 중복색을 가질수 있음
// k의 가장 작은 값을 알고 싶음 

bool tmp_check(string tmp, string tmpStr){
    if(tmpStr.find(tmp) != string::npos) {
        return true;
    }
    return false;
}

// s에서 tmp를 자른string에 값이 있는지 체르 
bool check(string tmp, string tmpStr){


    if(tmpStr.length() < tmp.length()){
        if(tmp.find(tmpStr) != string::npos) {
            return true;
        }
    }
    else if(tmpStr.length() > tmp.length()){
        if(tmpStr.find(tmp) != string::npos) {
            return true;
        }
    }
    
    if(tmpStr.find(tmp) != string::npos) {
        return true;
    }
    return false;
}
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);
    
   int N, answer = 1;
   string s;
   cin>>N;
   cin>>s;

//  원본
   for(int i=1;i<=s.length();i++){
      for(int j=0;j<s.length()-i;j++){
          cout<<"i: "<<i<<", j: "<<j<<"\n";
          for(int z=j+1;z<=j+i;z++){
            string tmp=s.substr(z,j);
            string tmpStr=s.substr(j+z, s.length()-j);
            cout<<"tmp: "<<tmp<<", tmpStr:"<<tmpStr<<"\n";
            // 만약 반복되는 값이 있으면 return 
            if(check(tmp, tmpStr)) {
                cout<<"find\n";
                //continue;
                break;
            } 
            cout<<i<<endl;
            return 0;
          }
         
      }
   }
   //
   

    while(answer <= N){
        bool ch = true;
        for(int i=0;i<N;i++){
            if(i + answer <= N){
                string tmp=s.substr(i, i + answer);
                string tmpStr=s.substr(i + answer, s.length()-answer);
                cout<<"tmp: "<<tmp<<", tmpStr:"<<tmpStr<<"\n";
                if(check(tmp, tmpStr)) {
                    cout<<"find\n";
                    //continue;
                    ch = false;
                    break;
                }
                 
            }

            if(!ch) break;
        }

        if(ch) break;
        answer++;
    }

   cout<<tmp_check("A","BCA")<<"\n";
   cout<<s.length();
   return 0;
} 

