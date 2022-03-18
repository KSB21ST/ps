#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define z third
int board[101][101][101]; //(height, row, column)
int vis[101][101][101];
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
int m, n, h;
queue<tuple<int, int, int> >Q;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> h;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                cin >> board[i][j][k];
                if(board[i][j][k] == 1){
                    vis[i][j][k] = 0;
                    Q.push({i, j, k});
                }
                else if(board[i][j][k] == -1){
                    vis[i][j][k] = 0;
                }else{
                    vis[i][j][k] = -1;                
                }
            }
        }
    }

    while(!Q.empty()){
        tuple<int, int, int> cur = Q.front(); Q.pop();
        for(int dir=0;dir<6;dir++){
            int nx = get<0>(cur) + dx[dir];
            int ny = get<1>(cur) + dy[dir];
            int nz = get<2>(cur) + dz[dir];
            if(nx < 0 || ny < 0 || nz < 0 || nx >= h || ny >= n || nz >= m) continue;
            if(vis[nx][ny][nz] >= 0 || board[nx][ny][nz] == -1 ) continue;
            vis[nx][ny][nz] = vis[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({nx, ny, nz});
        }
    }
    int ans = 0;
    for(int i=0;i<h;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(vis[i][j][k] < 0){
                    cout << -1;
                    return 0;
                }
                ans = max(ans, vis[i][j][k]);
            }
        }
    }    
    cout << ans;
}
/*
(거의) 바로 맞음..
vis 가 board 값이 1 때 일때와 -1 때 0 으로 설정해주고 나머지는 -1 로 설정해줘야 하는데
좀 헷갈렸음 (board 가 1일 때 vis 값을 0으롤 하고 board가 -1일 때 vis 값을 1 로 했었는데 그러니까 최종답이 0이 나오는 문제에서 1 이 나옴)
*/