#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[502][502];
int vis[502][502];
int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> board[i][j];
    int num = 0;
    int ms = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j] == 0 || vis[i][j] == 1) continue;
            num++;
            queue<pair<int, int> >Q;
            Q.push(make_pair(i, j));
            vis[i][j] = 1;
            int area = 0;
            while(!Q.empty()){
                pair<int, int> cur = Q.front(); Q.pop();
                area++;
                for(int dir = 0;dir<4;dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if(nx < 0 || nx > n - 1 || ny < 0 || ny > m - 1) continue;
                    if(board[nx][ny] == 0 || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push(make_pair(nx, ny));
                }
            }
            ms = max(ms, area);
        }
    }
    cout << num << "\n" << ms;
}