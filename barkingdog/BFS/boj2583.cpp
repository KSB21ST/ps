#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int board[101][101];
int vis[101][101];
int m, n, k;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> m >> n >> k;
    while(k--){
        int tx1, ty1, tx2, ty2;
        cin >> tx1 >> ty1 >> tx2 >> ty2;
        for(int i=m-ty2;i<(m-ty1);i++){
            for(int j=tx1;j<tx2;j++){
                board[i][j] = -1;
            }
        }
    }
    int num = 0;
    vector<int>v;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == -1 || vis[i][j] == 1) continue;
            num++;
            int area = 0;
            queue<pair<int, int> >Q;
            vis[i][j] = 1;
            Q.push(make_pair(i, j));
            while(!Q.empty()){
                pair<int, int> cur = Q.front(); Q.pop();
                area++;
                for(int dir=0;dir<4;dir++){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >=m || ny >= n) continue;
                    if(board[nx][ny] == -1 || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push(make_pair(nx, ny));
                }
            }
            v.push_back(area);
        }
    }
    cout << num << "\n";
    sort(v.begin(), v.end());
    for(auto k:v) cout << k << " ";
}
/*
한번에 맞음!
*/