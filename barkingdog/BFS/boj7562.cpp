#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int board[301][301];
int dist[301][301];
int dx[8] = {2, 1, 2, 1, -2, -1, -2, -1};
int dy[8] = {1, 2, -1, -2, 1, 2, -1, -2};
int t, n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        for(int i=0;i<n;i++) fill(dist[i], dist[i] + n, -1);
        queue<pair<int, int> >Q;
        dist[sx][sy] = 0;
        Q.push(make_pair(sx, sy));
        while(!Q.empty()){
            pair<int, int> cur = Q.front(); Q.pop();
            for(int dir=0;dir<8;dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || ny < 0 || nx >=n || ny >= n) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                Q.push(make_pair(nx, ny));
            }
        }
        cout << dist[ex][ey] << "\n";
    }
}
/*
한번에 맞음
*/