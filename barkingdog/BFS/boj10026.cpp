#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[101][101];
int vis1[101][101];
int vis2[101][101];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
        }
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(vis1[i][j] != 1){
                cnt1++;
                queue<pair<int, int> >Q;
                vis1[i][j] = 1;
                Q.push(make_pair(i, j));
                while(!Q.empty()){
                    pair<int, int> cur1 = Q.front(); Q.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur1.x + dx[dir];
                        int ny = cur1.y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(vis1[nx][ny] == 1 || board[nx][ny] != board[cur1.x][cur1.y]) continue;
                        vis1[nx][ny] = 1;
                        Q.push(make_pair(nx, ny));
                    }
                }
            }

            if(vis2[i][j] != 1){
                cnt2++;
                queue<pair<int, int> >Q2;
                vis2[i][j] = 1;
                Q2.push(make_pair(i, j));
                while(!Q2.empty()){
                    pair<int, int> cur2 = Q2.front(); Q2.pop();
                    for(int dir=0;dir<4;dir++){
                        int nx = cur2.x + dx[dir];
                        int ny = cur2.y + dy[dir];
                        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                        if(vis2[nx][ny] == 1) continue;
                        if(board[cur2.x][cur2.y] == 'R' || board[cur2.x][cur2.y] == 'G'){
                            if(board[nx][ny] == 'B') continue;
                        }else{
                            if(board[nx][ny] != board[cur2.x][cur2.y]) continue;
                        }
                        vis2[nx][ny] = 1;
                        Q2.push(make_pair(nx, ny));
                    }
                }
            }
        }
    }
    cout << cnt1 << " " << cnt2;
}
/*
유후 한 번에 맞음
방법은 맞았지만 char 비교할 때 바킹독 코드 참고
처음에 string board[101] 으로 했는데 ->  char board[101][101] 이런식으로 바꿈
*/