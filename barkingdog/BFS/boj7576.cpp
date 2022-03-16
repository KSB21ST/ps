#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[1002][1002];
int dist[1002][1002];
int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n;
    queue<pair<int, int> >Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == 1){
                Q.push(make_pair(i, j));
                dist[i][j] = 0;
            }
            if(board[i][j] == 0){
                dist[i][j] = -1;
            }
        }
    }
    while(!Q.empty()){
        pair<int, int> cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(dist[nx][ny] >= 0 || board[nx][ny] == -1) continue;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }
    int mx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(dist[i][j] == -1){
                cout << -1;
                return 0;
            }
            mx = max(mx, dist[i][j]);
        }
    }
    cout << mx;
}
/*
매우 당황스러웠다. 왜냐하면... 바킹독의 1926, 2178 번 풀이와 다르게 n 과 m 이 처음에 board를 채울 때 뒤바뀌어 있었기 때문이다.
와이..?
배치가 중요해서...?
왜 다른 문제들은 신경 안 씀..?
*/