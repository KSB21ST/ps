#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
string board[102];
int dist[102][102];
int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> board[i];
    for(int i=0;i<n;i++) fill(dist[i], dist[i] + m, -1);
    queue<pair<int, int> >Q;
    dist[0][0] = 0;
    Q.push(make_pair(0, 0));
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0 || nx > n-1 || ny > m -1 ) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] != '1') continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
    cout << dist[n-1][m-1] + 1;
}