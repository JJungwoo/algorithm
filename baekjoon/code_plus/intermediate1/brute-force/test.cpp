#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
/* 백준 에너지 모으기 16198 
첫번째 , 마지막 빼고 구슬을 고름 (x 번째)
x 번째 구슬 제거 -> 에너지 (wx-1 x wx+1)
*/


int n;
vector <int> v;
int result =0;
// 백터 배열, 지울 인덱스 , 길이 , 합
void dfs(vector <int> tempv, int a,  int sum){
    sum = sum +tempv[a-1]* tempv[a+1];
   // cout << sum <<"\n";
   //cout <<"a : " <<a<<"\n";
    tempv.erase(tempv.begin() +a); // 들어오고 지움
    
    if(tempv.size() == 2){ // 다 지웠나? 2
    //yes
        result = max(result, sum);    
        return ;
    }
    int maxvalue = -1;
    queue <int> next;
    for(int k  = 1 ; k < tempv.size()-1 ; k++){
        int temp = tempv[k-1]* tempv[k+1];
        if( temp == maxvalue){
            next.push(k);
        }else if(temp > maxvalue){
            while(!next.empty()){
                next.pop();
            }
            next.push(k);
            maxvalue = temp;
        }
    }

     while(!next.empty()){    
        int d = next.front();
     //   cout <<"d : " <<d <<"\n";
        dfs(tempv,d,sum);         
        next.pop();
    }
   
}

int main(){
    ios_base::sync_with_stdio(0);
    cout.tie(0); cin.tie(0);
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int a;
        cin >> a;
        v.push_back(a);
    } // 숫자 입력 받음

    queue <int> start;
    int maxvalue = -1;
    // 시작 위치 설정
    for(int i = 1 ; i < n-1 ; i++){
        int temp = v[i-1]* v[i+1];
        if( temp == maxvalue){
            start.push(i);
        }else if(temp > maxvalue){
            while(!start.empty()){
                start.pop();
            }
            start.push(i);
            maxvalue = temp;
        }
    }
    
    while(!start.empty()){    
        int a = start.front();
        int sum = 0;
        vector <int> tmpv(v); // 백터 복사
        //cout <<"a : " <<a<<"\n";
        dfs(tmpv,a, sum);       
        start.pop();
        tmpv.clear();
    }
   
    cout << result <<"\n";

}
