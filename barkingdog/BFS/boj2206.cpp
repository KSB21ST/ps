#include <bits/stdc++.h>
using namespace std;

/*
// 첫 번째 접근: 모든 1인 애들을 차례로 순회했는데, 그렇게 되면 worse case 에서 O(MN^2) (M: 0 개수, N: 1개수) 가 나오기 때문에 시간초과 ending
#define x first
#define y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string board[1002];
int dist[1002][1002];
int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<pair<int, int> >walls;
    vector<pair<int, int> >v;
    for(int i=0;i<n;i++){
        cin >> board[i];
        for(int j=0;j<m;j++){
            if(board[i][j] == '1') v.push_back({i, j});
        }
    }

    for(auto cur : v){
        int cnt = 0;
        for(int dir=0;dir<4;dir++){
            int ni = cur.x + dx[dir];
            int nj = cur.y + dx[dir];
            if(ni < 0 || nj < 0 || ni >=n || nj >= m) continue;
            if(board[ni][nj] == '0') cnt++;
        }
        if(cnt >= 2) walls.push({cur.x, cur.y});
    }

    int mx = 1000002;
    bool success = false;
    while(!walls.empty()){
        pair<int, int> cur_wall = walls.front(); walls.pop();
        board[cur_wall.x][cur_wall.y] = '0';
        queue<pair<int, int> >Q;
        dist[0][0] = 1;
        Q.push({0, 0});
        while(!Q.empty()){
            pair<int, int> cur = Q.front(); Q.pop();
            for(int dir=0;dir<4;dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= n || ny >= m ) continue;
                if(board[nx][ny] == '1' || dist[nx][ny] > 0) continue;
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                Q.push({nx, ny});
            }
        }
        if(dist[n-1][m-1] > 0){
            mx = min(mx, dist[n-1][m-1]);
            success = true;
        }
        board[cur_wall.x][cur_wall.y] = '1';
        for(int i=0;i<n;i++) fill(dist[i], dist[i] + m, 0);
    }
    if(success){
        cout << mx;
    }else{
        cout << -1;
    }
}       
*/

#define x first
#define y second
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char board[1002][1002];
int dist[1002][1002][2]; //벽을 부순 상태, 부수지 않은 상태 구분
int n, m;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            fill(dist[i][j], dist[i][j] + 2, -1);
        }
    }
    
    
    queue<tuple<int, int, int> >Q;
    dist[0][0][0] = dist[0][0][1] = 1;
    Q.push({0, 0, 0}); //0 not break any tiles, 1 broke tile before
    while(!Q.empty()){
        int x, y, broken;
        tie(x, y, broken) = Q.front(); Q.pop();
        for(int dir=0;dir<4;dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx == n-1 && ny == m-1){
                cout << dist[x][y][broken] + 1;
                return 0;
            }
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == '0' && dist[nx][ny][broken] == -1){
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                Q.push({nx, ny, broken});
            }
            if(board[nx][ny] == '1' && broken == 0 && dist[nx][ny][1] == -1){
                dist[nx][ny][1] = dist[x][y][broken] + 1;
                Q.push({nx, ny, 1});
            }
        }
    }
    int ans = min(dist[n-1][m-1][0], dist[n-1][m-1][1]);
    cout << ans;
}       

/*
결국에는 바킹독 풀이를 한 번 보고, 해설도 찾아보고 푼 문제. (다시 풀어보기!)
구현을 내가 하긴 했지만..
되게 오랫동안 고민했는데, 생각보다 풀이 방법이 단순했다.
벽을 부수었는지 안 부수었는지 상태만 두 가지로 놓고,
트랙을 두 개로 돌리듯이 풀면 되었던 문제...
처음에는 어떤 벽을 부수냐에 따라서 값이 다 달라져서, 각각의 벽에 대해서 부술 때마다 경우의 수를 따져줘야한다고 생각했는데,
생각해보면 그냥 각 칸에 대해 벽을 부쉈는지 안 부쉈는지만 생각을 해주면 초기에 벽을 처음 부술 때를 제외하면 (이전 거리 값) + 1 은 똑같기 때문에.. 
하여튼 풀이를 보고 나니까 왜 이렇게 복잡하게 생각했지.. 라는 생각이 드는데
막상 복기해보면 어떻게 왜 복잡하게 생각이 된건지 기억이 잘 안 난다.
아무튼 다시 풀어보기
*/