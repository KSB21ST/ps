#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
int board[51][51];
int vis[51][51];
int m, n, k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--){
        cin >> m >> n >> k;
        for(int i=0;i<k;i++){
            int x_b, y_b;
            cin >>  x_b >> y_b;
            board[y_b][x_b] = 1;
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == 0 || vis[i][j] == 1) continue;
                cnt++;
                queue<pair<int, int> >Q;
                vis[i][j] = 1;
                Q.push(make_pair(i, j));
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        Q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        cout << cnt << "\n";
        for(int i=0;i<n;i++) {
            fill(board[i], board[i] + m, 0);
            fill(vis[i], vis[i] + m, 0);
        }
        
    }
}
/*
한 iteration이 끝나고 board, vis 를 비워주는 작업을 뺴먹어서 틀림 ㅠㅠ
나머지는 내가 온전히 짜서 맞음.
*/