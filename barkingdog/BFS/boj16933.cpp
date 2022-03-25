#include <bits/stdc++.h>
using namespace std;
char board[1002][1002];
int dist[1002][1002][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m, k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    if(n==1 && m==1){
        cout << 1;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(i==0 && j==0)
                fill(dist[i][j], dist[i][j] + 10, 1);
            else
                fill(dist[i][j], dist[i][j] + 10, 0);
        }
    }
    queue<tuple<int, int, int, int> >Q;
    Q.push({0, 0, 0, 1});
    while(!Q.empty()){
        int x, y, f, d;
        tie(x, y, f, d) = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(nx == n-1 && ny == m-1){
                cout << dist[x][y][f] + 1;
                return 0;
            }
            //벽을 부수지 않는 경우
            if(board[nx][ny] == '0' && dist[nx][ny][f] <= 0){
                dist[nx][ny][f] = dist[x][y][f] + 1;
                Q.push({nx, ny, f, 1-d});
            }
            //벽을 부수는 경우
            if(f < k && board[nx][ny] == '1' && dist[nx][ny][f+1] <= 0){
                if(d){
                    if(dist[nx][ny][f+1] == 0){
                        dist[nx][ny][f+1] = dist[x][y][f] + 1;
                    }else{
                        dist[nx][ny][f+1] = dist[x][y][f] + 2;
                    }
                    Q.push({nx, ny, f+1, 1-d});
                }
                else{
                    dist[nx][ny][f+1] = -1;
                    Q.push({x, y, f, 1-d});
                }
            }
        }   
    }
    cout << -1;
}
/*
일단 보류. 아직 안풀렸음. 나중에 다시 풀어보기
*/