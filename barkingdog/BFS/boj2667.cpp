#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
char board[26][26];
int vis[26][26];
int n;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> board[i];
    }
    int num = 0;
    vector<int>v;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(board[i][j] == '0' || vis[i][j] == 1) continue;
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
                    if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if(board[nx][ny] == '0' || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q.push(make_pair(nx, ny));
                }
            }
            v.push_back(area);
        }
    }
    cout << num << "\n";
    sort(v.begin(), v.end());
    for(auto k:v) cout << k << "\n";
}
/*
(거의) 한 방에 맞음
sort 빼먹음
*/