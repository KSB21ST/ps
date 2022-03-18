#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define x third
int dx[6] = {1, 0, 0, -1, 0, 0};
int dy[6] = {0, 1, 0, 0, -1, 0};
int dz[6] = {0, 0, 1, 0, 0, -1};
char board[31][31][31]; //(height, row, column)
int dist[31][31][31];
int l, r, c;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(1){
        cin >> l >> r >> c;
        if(l == 0 && r == 0 && c == 0)
            return 0;
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                fill(dist[i][j], dist[i][j] + c, -1);
            }
        }
        int ex, ey, ez;
        queue<tuple<int, int, int> >Q;
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    cin >> board[i][j][k];
                    if(board[i][j][k] == 'S'){
                        dist[i][j][k] = 0;
                        Q.push({i, j, k});
                    }
                    if(board[i][j][k] == 'E'){
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
            }
        }

        while(!Q.empty()){
            tuple <int, int, int> cur = Q.front(); Q.pop();
            for(int dir=0;dir<6;dir++){
                int nx = get<0>(cur) + dx[dir];
                int ny = get<1>(cur) + dy[dir];
                int nz = get<2>(cur) + dz[dir];
                if(nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c) continue;
                if(board[nx][ny][nz] == '#' || dist[nx][ny][nz] >= 0) continue;
                dist[nx][ny][nz] = dist[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
                Q.push({nx, ny, nz});
            }
        }
        if(dist[ex][ey][ez] >= 0){
            cout << "Escaped in " << dist[ex][ey][ez] << " minute(s).\n";
        }else{
            cout << "Trapped!\n";
        }
    }

}
/*
한 번에 맞음
*/