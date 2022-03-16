#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
string board[1002];
int f_dist[1002][1002];
int j_dist[1002][1002];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    int j_x, j_y, f_x, f_y;

    for(int i=0;i<n;i++){
        fill(f_dist[i], f_dist[i] + m, -1);
        fill(j_dist[i], j_dist[i] + m, -1);
    }
    for(int i=0;i<n;i++)
        cin >> board[i];

    queue<pair<int, int> >Q;
    queue<pair<int, int> >Q2;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 'J'){
                j_dist[i][j] = 0;
                Q2.push(make_pair(i, j));
                j_x = i;
                j_y = j;
            }
            if(board[i][j] == 'F'){
                f_dist[i][j] = 0;
                Q.push(make_pair(i, j));
                f_x = i;
                f_y = j;
            }
        }
    }
    
    /*Q.push(make_pair(f_x, f_y)) <-- 이렇게 하면 안된다. 
    생각해보니 아예 F 가 없는 경우가 있을수도.
    */
    while(!Q.empty()){
        pair<int, int> f_cur = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = f_cur.x + dx[dir];
            int ny = f_cur.y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(f_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            f_dist[nx][ny] = f_dist[f_cur.x][f_cur.y] + 1;
            Q.push(make_pair(nx, ny));
        }
    }

    while(!Q2.empty()){
        pair<int, int> j_cur = Q2.front(); Q2.pop();
        for(int dir=0;dir<4;dir++){
            int nx = j_cur.x + dx[dir];
            int ny = j_cur.y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                cout << j_dist[j_cur.x][j_cur.y] + 1;
                return 0;
            }
            if(j_dist[nx][ny] >= 0 || board[nx][ny] == '#') continue;
            if(j_dist[j_cur.x][j_cur.y] + 1 >= f_dist[nx][ny] && f_dist[nx][ny] != -1) continue;
            j_dist[nx][ny] = j_dist[j_cur.x][j_cur.y] + 1;
            Q2.push(make_pair(nx, ny));
        }
    }
    cout << "IMPOSSIBLE";
}