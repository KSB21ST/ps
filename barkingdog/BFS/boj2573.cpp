#include <bits/stdc++.h>
using namespace std;
// #define x
// #define y
int board[302][302];
int vis[302][302];
int near[302][302];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    queue<tuple<int, int, int> >Q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            near[i][j] = 0;
            cin >> board[i][j];
        }
    }

    // for(int i=1;i<n-1;i++){
    //     for(int j=1;j<m-1;j++){
    //         int num_ice = 0;
    //         for(int dir=0;dir<4;dir++){
    //             int nx = i + dx[dir];
    //             int ny = j + dy[dir];
    //             if(nx < 0 || ny < 0 || nx >=n || ny >= m) continue;
    //             if(board[nx][ny] == 0) num_ice++;
    //         }
    //         near[i][j] = num_ice;
    //     }
    // }

    int time = 0;
    while(1){
        int num = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 0 || vis[i][j] == 1) continue;
                num++;
                if(num >= 2){
                    cout << time;
                    return 0;
                }
                queue<pair<int, int> >Q;
                vis[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()){
                    int x, y;
                    tie(x, y) = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(board[nx][ny] == 0) {near[x][y]++; continue;}
                        if(vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                    // board[x][y] = max(0, board[x][y] - near[x][y]);
                }
            }
        }
        if(num == 0){
            cout << 0;
            return 0;
        }

        time++;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++){
                if(board[i][j] == 0) continue;
                board[i][j] = max(0, board[i][j] - near[i][j]);
                vis[i][j] = 0;
                near[i][j] = 0;
            }
        }
    }
}
/*
바보 같이..
66 번째 줄에서 n = 0 인 경우를 빠뜨려서 계속 시간초과 남 .. ;;
*/