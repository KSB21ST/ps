#include <bits/stdc++.h>
using namespace std;
int vis[101][101];
int light[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int> >q[101][101];
queue<pair<int, int> >Q;
int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x <= 0 || y <= 0 || x > n || y > n) continue;
        if(a <= 0 || b <= 0 || a > n || b > n) continue;
        q[x-1][y-1].push({a-1, b-1});
    }
    for(int i=0;i<n;i++) {
        fill(vis[i], vis[i]+n, 0);
        fill(light[i], light[i]+n, 0);
    }
    vis[0][0] = 1;
    light[0][0] = 1;
    Q.push({0, 0});
    int cnt = 0;
    while(!Q.empty()){
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        while(!q[x][y].empty()){ //current 방에서 켜줄 수 있는 스위치는 다 켜준다
            int a, b;
            tie(a, b) = q[x][y].front(); q[x][y].pop();
            if(light[a][b] > 0 || vis[a][b] > 0) continue;
            light[a][b] = 1;
            int isPushed = 0;
            for(int dir=0;dir<4;dir++){
                if(isPushed) break;
                int na = a + dx[dir]; 
                int nb = b + dy[dir];
                if(na < 0 || nb < 0 || na >= n || nb >= n) continue;
                if(vis[na][nb]) {
                    vis[a][b] = 1;
                    Q.push({a, b});
                    isPushed = 1;
                }
            }
        }
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if(vis[nx][ny]) continue;
            if(!light[nx][ny]) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(light[i][j]) cnt++;
        }
    }
    cout << cnt;
}
/*
한 번에 맞음!
맨 나중에 cnt 세어줄 때 Light 를 세어야 하는데 vis 를 세 버림 ㅠㅠ
중요한 건 light과 vis 가 서로 싱크가 안 맞을 수도 있지만, 만약 새로 켜진 light가 vis 영역과 바로 인접해있다면 queue에 push 해줄 것. 유의
*/