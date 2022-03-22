#include <bits/stdc++.h>
using namespace std;
char board[1002][1002];
int dist[1002][1002][11];
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if(n == 1 && m == 1){
        cout << 0;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(i==0 && j==0)
                fill(dist[i][j], dist[i][j] + 11, 1);
            else
                fill(dist[i][j], dist[i][j] + 11, -1);
        }
    }

    queue<tuple<int, int, int> >Q;
    Q.push({0, 0, 0});
    while(!Q.empty()){
        int x, y, f;
        tie(x, y, f) = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(nx == n-1 && ny == m-1){
                cout << dist[x][y][f] + 1;
                return 0;
            }
            //벽을 부수는 경우
            if(f < k && board[nx][ny] == '1' && dist[nx][ny][f+1] < 0){
                dist[nx][ny][f+1] = dist[x][y][f] + 1;
                Q.push({nx, ny, f+1});
            }
            //벽을 부수지 않는 경우
            if(board[nx][ny] == '0' && dist[nx][ny][f] < 0){
                dist[nx][ny][f] = dist[x][y][f] + 1;
                Q.push({nx, ny, f});
            }
        }
    }
    cout << -1;
}
/*
어이없게...
n == 1 && m == 1 일 때 cout << 0 대신 cout << 1 해줬더니 맞음.. -> 이것때매 시간낭비 ㅠㅠ
유형은 벽 부수기1 확장
*/