#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
char board[1001][1001];
int dist1[1001][1001];
int dist2[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int t, w, h;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--){
        cin >> w >> h;
        queue<pair<int, int> >Q1;
        queue<pair<int, int> >Q2;
        for(int i=0;i<h;i++){
            cin >> board[i];
        }
        for(int i=0;i<h;i++){
            fill(dist1[i], dist1[i] + w, -1);
            fill(dist2[i], dist2[i] + w, -1);
        }
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(board[i][j] == '@'){
                    dist2[i][j] = 0;
                    Q2.push(make_pair(i, j));
                }
                if(board[i][j] == '*'){
                    dist1[i][j] = 0;
                    Q1.push(make_pair(i, j));
                }
            }
        }

        while(!Q1.empty()){
            pair<int, int> cur1 = Q1.front(); Q1.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur1.x + dx[dir];
                int ny = cur1.y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
                if(board[nx][ny] == '#' || dist1[nx][ny] >= 0) continue;
                dist1[nx][ny] = dist1[cur1.x][cur1.y] + 1;
                Q1.push(make_pair(nx, ny));
            }     
        }

        // for(int i=0;i<h;i++){
        //     for(int j=0;j<w;j++){
        //         cout << dist1[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        int success = 0;
        int cur_x, cur_y;
        while(!Q2.empty()){
            pair<int, int> cur2 = Q2.front(); Q2.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur2.x + dx[dir];
                int ny = cur2.y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= h || ny >= w){
                    if(!success){
                        success = 1;
                        cur_x = cur2.x;
                        cur_y = cur2.y;
                        break;
                    }
                }
                if(board[nx][ny] == '#' || dist2[nx][ny] >= 0) continue;
                if(dist2[cur2.x][cur2.y] + 1 >= dist1[nx][ny] && dist1[nx][ny] >=0) continue; //불이 먼저 도착했을 떄
                dist2[nx][ny] = dist2[cur2.x][cur2.y] + 1;
                Q2.push(make_pair(nx, ny));
            }     
            if(success)
                break;
        }
        if(!success){
            cout << "IMPOSSIBLE" << "\n";
        }else{
            cout << dist2[cur_x][cur_y] + 1 << "\n";
        }
    }
}
/*
계속 틀리다가 전에 틀렸던 불1 을 봤다 (boj 4179)
74번 if(dist2[cur2.x][cur2.y] + 1 >= dist1[nx][ny]) 에 뒤어 dist1[nx][ny] >= 0 조건을 추가해줬더니 맞았다
불이 애기랑 벽으로 뭔가 분리되었을 때 틀렸을 것 같다
*/