/*
[BOJ] 17281. 야구
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n, locate, ans;
int player[50][9], seq[9];
bool visited[9];

int bfs(){
    int out = 0, inning = 0, score = 0;
    int ground[4] = {0,};
    locate = 0;
    while(1){
        
        //cout<<locate<<" inning:"<<inning<<" out:"<<out<<", "<<player[inning][seq[locate]]<<"\n";
        switch(player[inning][seq[locate]]){
            case 0: // out
            out++;
            break;
            case 1:
            ground[3] = ground[2];
            ground[2] = ground[1];
            ground[1] = ground[0];
            ground[0] = 1;
            break;
            case 2:
            ground[3] = ground[2] + ground[1];
            ground[2] = ground[0];
            ground[1] = 1;
            ground[0] = 0;
            break;
            case 3:
            ground[3] = ground[2] + ground[1] + ground[0];
            ground[2] = 1;
            ground[1] = 0;
            ground[0] = 0;
            break;
            case 4:
            ground[3] = ground[2] + ground[1] + ground[0] + 1;
            ground[2] = 0;
            ground[1] = 0;
            ground[0] = 0;
            break;
        }

        score += ground[3];
        ground[3] = 0;

        if(out == 3){
            //cout<<score<<", "<<inning<<"\n";
            inning++;
            out = 0;
            memset(ground, 0, sizeof(ground));
        }

        if(inning == n){
            return score;
        }
        //locate = (locate + 1) % 9;
        locate++;
        if(locate == 9){
            locate = 0;
        }
    }
}

void dfs(int cnt){
    if(cnt == 9){
        ans = max(ans, bfs());
    }

    if(cnt == 3) {  
        seq[cnt] = 0;
        dfs(cnt + 1);
    }
    else {
        for(int i=1;i<9;i++){
            if(!visited[i]){
                visited[i] = true;
                seq[cnt] = i;
                dfs(cnt+1);
                visited[i] = false;
            }
        }
    }
}

int main()
{
    io;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<9;j++){
            cin>>player[i][j];
        }
    }

    dfs(0);
    cout<<ans<<"\n";

    return 0;
}