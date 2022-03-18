#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[102][102];
int vis[102][102];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int mix = 101;
    int mx = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            mix = min(board[i][j], mix);
            mx = max(board[i][j], mx);
        }
    }
    int max_area = 0;
    for(int h=mix;h<mx+1;h++){
        int num = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j] == 1 || board[i][j] < h) continue;
                num++;
                queue<pair<int, int> >Q;
                vis[i][j] = 1;
                Q.push(make_pair(i, j));
                while(!Q.empty()){
                    pair<int, int> cur = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur.x + dx[dir];
                        int ny = cur.y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(board[nx][ny] < h || vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        Q.push(make_pair(nx, ny));
                    }
                }
            }
        }
        max_area = max(num, max_area);
        for(int i=0;i<n;i++) fill(vis[i], vis[i] + n, 0);
    }
    cout << max_area;
}
/*
한 번에 맞음
*/