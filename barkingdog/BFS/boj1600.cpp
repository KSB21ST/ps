#include <bits/stdc++.h>
using namespace std;
int board[202][202];
int dist[202][202][32];
int dx1[8] = {2, 1, -2, -1, 2, 1, -2, -1};
int dy1[8] = {1, 2, 1, 2, -1, -2, -1, -2};
int dx2[4] = {1, 0, -1, 0};
int dy2[4] = {0, 1, 0, -1};
int k, w, h;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cin >> w >> h;
    if(w == 1 && h == 1){
        cout << 0;
        return 0;
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> board[i][j];
            if(i == 0 && j == 0)
                fill(dist[i][j], dist[i][j] + 32, 0);
            else
                fill(dist[i][j], dist[i][j] + 32, -1);
        }
    }
    queue<tuple<int, int, int> >Q;
    Q.push({0, 0, 0});
    while(!Q.empty()){
        int x, y, horse;
        tie(x, y, horse) = Q.front(); Q.pop();
        // cout << "x: " << x << " y: " << y << " horse: " << horse << "\n";
        //horse jump 안 하는 경우
        for(int dir=0;dir<4;dir++){
            int nx = x + dx2[dir];
            int ny = y + dy2[dir];
            if(nx < 0 || ny < 0 || nx >=h || ny>=w) continue;
            if(nx == h-1 && ny == w-1){
                cout << dist[x][y][horse] + 1;
                return 0;
            }
            if(board[nx][ny] == 1 || dist[nx][ny][horse] >= 0) continue;
            dist[nx][ny][horse] = dist[x][y][horse] + 1;
            Q.push({nx, ny, horse});
        }
        //horse jump 하는 경우
        if(horse < k){
            for(int dir=0;dir<8;dir++){
                int nx = x + dx1[dir];
                int ny = y + dy1[dir];
                if(nx < 0 || ny < 0 || nx >=h || ny>=w) continue;
                if(nx == h-1 && ny == w-1){
                    cout << dist[x][y][horse] + 1;
                    return 0;
                }
                if(board[nx][ny] == 1 || dist[nx][ny][horse + 1] >= 0) continue;
                dist[nx][ny][horse + 1] = dist[x][y][horse] + 1;
                Q.push({nx, ny, horse + 1});
            }
        }
    }
    cout << -1;
}
/*
와우.. 100% 까지 갔는데 틀렸습니다 떠서.. w==1 && h==1 인 경우 처리해줬더니 맞음..
유형은.. 벽 부수고 이동하기(2206) 과 동일!
벽 부수면서 고생한 보람이 있었네...
*/