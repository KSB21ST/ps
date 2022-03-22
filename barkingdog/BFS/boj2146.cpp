#include <bits/stdc++.h>
using namespace std;
int board[101][101];
int vis[101][101];
int vis2[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int init = 0;
    queue<pair<int, int> >Q;
    for(int i=0;i<n;i++) {
        fill(vis[i], vis[i] + n, -1);
        fill(vis2[i], vis2[i] + n, -1);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> board[i][j];
            if(board[i][j] == 1 && !init){
                init = 1;
                vis[i][j] = 0;
                Q.push({i, j});
            }
        }
    }

    int min_dist = 300;
    queue<pair<int, int> > sea_q;
    while(1){
        while(!Q.empty()){
            int x, y;
            tie(x, y) = Q.front(); Q.pop();
            for(int dir=0;dir<4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(vis[nx][ny] >= 0) continue;
                if(vis2[nx][ny] >= 0) continue;
                if(board[nx][ny] == 0){
                    // vis[nx][ny] = 0;
                    vis2[nx][ny] = 1;
                    sea_q.push({nx, ny});
                    continue;
                }
                vis[nx][ny] = 0;
                Q.push({nx, ny});
            }
        }
        
        // cout << "\nvis\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << "\n";
        // }


        while(!sea_q.empty()){
            int x, y;
            tie(x, y) = sea_q.front(); sea_q.pop();
            for(int dir=0;dir<4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                if(vis2[nx][ny] >= 0) continue;
                if(vis[nx][ny] >= 0) continue;
                if(board[nx][ny] == 1 && vis2[nx][ny] < 0){ //새로운 대륙 발견!
                    min_dist = min(min_dist, vis2[x][y]);
                    vis[nx][ny] = 0;
                    Q.push({nx, ny});
                    while(!sea_q.empty()){
                        sea_q.pop();
                    }
                    break;
                }
                if(board[nx][ny] == 0){
                    vis2[nx][ny] = vis2[x][y] + 1;
                    sea_q.push({nx, ny});
                }
            }
        }

        // cout << "\nvis\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout << vis[i][j] << " ";
        //     }
        //     cout << "\n";
        // }
        for(int i=0;i<n;i++) fill(vis2[i], vis2[i] + n, -1);


        if(Q.empty()){
            cout << min_dist;
            return 0;
        }
    }

}
/*
왜.. 맞은거지..?
계속 시간초과 나서 방법을 바꿨더니 틀렸는데.. 다시 원래 방식대로 하니까 맞음>>?
흠.. 뭔가 두 번째 while loop 에서 continue 조건을 빼먹어서 그런 것 같다 (시간초과 나는 풀이는,,)
이 문제는 우선 대륙 하나를 찍어서 bfs 돈다음,(첫 번째 while loop) -> vis 에 방문 여부 저장
그 주변머리에 있는 바다에 대해서 bfs 를 돈다 (두 번째 while loop) -> vis2 에 거리 정보 저장
그리고 돌다가 가장 근처에 있는 육지를 찾게 되면 그 육지에 대해 bfs 를 다시 돈다 (다시 첫번째 while loop) -> vis 에 방문여부 저장
이 때 중요한건 주변머리 바다를 다시 초기화해서 (vis2를 초기화) 거리 1 부터 시작하는 거다. 
그래서 두 번째로 두번째 while loop (처음부터 따지면 4번째 while loop)
은 두 번째로 발견한 육지에 대한 거리를 저장해야한다. 
왜냐하면 vis2를 초기화하지 않으면 전에 구했던 vis2 때문에 (vis2 >= 0) continue; 여기서 다 패스해버리게 된다
그런식으로 대륙별로 육지를 다 돈다음에 (이미 전에 체크했던 육지인지는 vis 로 체크)
끝을 낸다
*/