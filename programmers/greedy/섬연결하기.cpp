#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int visited[101];
bool com(vector<int> a, vector<int> b){
    return a[2] < b[2];
}
void init(int n){
    for(int i=0;i<n;i++)
        visited[i] = i;
}
int find(int v){
    if(visited[v] == v) return v;
    else return visited[v] = find(visited[v]);
}
void uni(int p, int q){
    p = find(p);
    q = find(q);
    if(p == q) return;
    visited[p] = q;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0, cnt = 1;
    sort(costs.begin(), costs.end(), com);
    init(n);
    for(int i=0;i<costs.size();i++){
        int cur = costs[i][0], next = costs[i][1];
        if(find(cur) != find(next)){
            uni(cur, next);
            cnt++;
            answer += costs[i][2];
            if(cnt == n) break;
        }
        //cout<<costs[i][0]<<","<<costs[i][1]<<","<<costs[i][2]<<"\n";
    }
    return answer;
}
