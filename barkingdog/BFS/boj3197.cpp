/*
#include <bits/stdc++.h>
using namespace std;
char board[1501][1501];
int vis[1501][1501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int r, c;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> c;
    int x1, y1, x2, y2;
    bool first = true;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> board[i][j];
            if(board[i][j] == 'L'){
                if(first){
                    x1 = i;
                    y1 = j;
                    first = false;
                }else{ 
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    if(x1 == x2 && y1 == y2){
        cout << 0;
        return 0;
    }

    queue<pair<int, int> >g;
    for(int i=0;i<r;i++) fill(vis[i], vis[i] + c, -1);
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(vis[i][j] >= 0 || board[i][j] == 'X') continue;
            queue<pair<int, int> >Q;
            vis[i][j] = 0;
            Q.push({i, j});
            while(!Q.empty()){
                int x, y;
                tie(x, y) = Q.front(); Q.pop();
                for(int dir=0;dir<4;dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                    if(vis[nx][ny] >= 0) continue;
                    if(board[nx][ny] == 'X'){
                        vis[nx][ny] = 1;
                        g.push({nx, ny});
                        continue;
                    }
                    vis[nx][ny] = 0;
                    Q.push({nx, ny});
                }
            }
        }
    }
    while(!g.empty()){
        int x, y;
        tie(x, y) = g.front(); g.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
            if(board[nx][ny] == '.') continue;
            if(vis[nx][ny] >= 0) continue;
            vis[nx][ny] = vis[x][y] + 1;
            g.push({nx, ny});
        }
    }
}
 
일차시도. 처음에는 그냥 평범한 bfs 로 했는데 (백조가 서로 만날 때까지 bfs 돌리기) 자꾸 시간초과가 떠서 다른 번뜩이는 아이디어가 필요한가?
생각해서 실시간으로 bfs 돌리지 않고 초기에 물인 애들로부터 거리를 bfs 로 돌려서 정적인 거리 벡터 맵을 짰는데...
한 백조에서 다른 백조로 최단 거리를 구하는 것에서 막혔다. 그래서 결국 답을 봤는데... 처음 생각했던 무식하게 돌리는 bfs로 풀었길래.. ㅜ머지... 
다만 next queue를 썼다는 게 다른데.. <확장게임 boj16920> 에서도 next queue를 썼던 것 같은데 이거랑은 많이 달랐던 것 같다.
유형은 <빙산 boj2573> 하고 똑같아서 처음에 그렇게 푼 건데.. 자꾸 시간초과남...
*/


//second try
#include <bits/stdc++.h>
using namespace std;
string board[1501];
int vis[1501][1501];
int wvis[1501][1501];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int> >SQ; //swan queue
queue<pair<int, int> >NSQ; //next swan queue
queue<pair<int, int> >WQ; //water queue
queue<pair<int, int> >NWQ; //next water queue
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int r, c, tx, ty = 0;
    cin >> r >> c;
    for(int i=0;i<r;i++) {
        cin >> board[i];
        fill(vis[i], vis[i]  + 1501, 0);
        fill(wvis[i], wvis[i] + 1501, 0);
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(board[i][j] == 'L'){
                tx = i;
                ty = j;
            }
            if(board[i][j] != 'X'){
                WQ.push({i, j});
            }
        }
    }

    vis[tx][ty] = 1;
    SQ.push({tx, ty}); // 백조 한 놈만 queue에 넣는다
    board[tx][ty] = '.';

    int time = 0;
    bool swan = false;
    while(!swan){
        while(!WQ.empty()){
            int wx, wy;
            tie(wx, wy) = WQ.front(); WQ.pop();
            wvis[wx][wy] = 1;
            for(int dir=0;dir<4;dir++){
                int nwx = wx + dx[dir];
                int nwy = wy + dy[dir];
                if(nwx < 0 || nwy < 0 || nwx >= r || nwy >= c) continue;
                if(wvis[nwx][nwy]) continue;
                wvis[nwx][nwy] = 1;
                if(board[nwx][nwy] == 'X')
                    NWQ.push({nwx, nwy});
            }
        }

        while(!NWQ.empty()){
            int x, y;
            tie(x, y) = NWQ.front(); NWQ.pop();
            board[x][y] = '.';
            WQ.push({x, y});
        }
        time++;

        while(!SQ.empty()){
            int sx, sy;
            tie(sx, sy) = SQ.front(); SQ.pop();
            // cout << "SQ: " << sx << " " << sy << "\n";
            for(int dir=0;dir<4;dir++){
                int nsx = sx + dx[dir];
                int nsy = sy + dy[dir];
                if(nsx < 0 || nsy < 0 || nsx >= r || nsy >= c) continue;
                if(vis[nsx][nsy]) continue;
                vis[nsx][nsy] = 1;
                if(board[nsx][nsy] == 'X'){
                    NSQ.push({nsx, nsy});
                    continue;
                }
                if(board[nsx][nsy] == 'L'){
                    swan = true;
                    break;
                }
                SQ.push({nsx, nsy});
            }
        }

        while(!NSQ.empty()){
            int x, y;
            tie(x, y) = NSQ.front(); NSQ.pop();
            SQ.push({x, y});
        }

    }
    cout << time;
}
/*
워후.. 문제 난이도에 비해 생각보다 오래 걸렸다.. ㅠㅠ
핵심은 물과 백조에 대한 queue와 nextqueue 를 각각 만들어줘서 (그러면 queue가 4개) X를 만날 때마다 queue에 넣어주는 것이다.
다만, 엄청나게 오랫동안 디버깅을 했는데 그 이유는 visit 을 각각 따로 만들어주지 않아서.. ㅠㅠ
다른 풀이 보니까 visit 을 물은 아예 없애고 진행하기도 하던데, 아무튼 너무 성급하게 풀었던 것 같다.
다시 풀면 잘 풀 수 있을 것 같은데.. 그냥 내 머리가 생각하기 실었나보다.
*/