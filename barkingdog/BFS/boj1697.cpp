#include <bits/stdc++.h>
using namespace std;
int board[200002];
int dist[200002];
int d[3] = {-1, 1, 2};
int n, k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    fill(dist, dist + 200001, -1);
    queue<int>Q;
    dist[n] = 0;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int dir=0;dir<3;dir++){
            int nx;
            if(d[dir] == 2)nx = cur*2;
            else nx = cur + d[dir];
            if(dist[nx] >= 0 || nx < 0 || nx > 100000) continue;
            /*
            if(nx == k){
                cout << dist[cur] + 1;
                return 0;
            }
            --> 이 부분만 있으면 틀렸다고 나옴.. 왜일까??
            */
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    cout << dist[k];
}