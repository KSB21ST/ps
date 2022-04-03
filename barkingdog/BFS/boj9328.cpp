#include <bits/stdc++.h>
using namespace std;
char board[102][102];
int vis[102][102];
int key[27];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N, h, w;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--){
        int ans = 0;
        for(int i=0;i<101;i++){
            fill(vis[i], vis[i] + 102, -1);
            fill(board[i], board[i] + 102, 0);
        }
        fill(key, key + 27, 0);
        cin >> h >> w;
        for(int i=1;i<h+1;i++){
            for(int j=1;j<w+1;j++){
                cin >> board[i][j];
            }
        }
        string key_lst;
        cin >> key_lst;
        for(auto k : key_lst){ /*가지고 있는 key 를 key array 안에 저장해준다*/
            if(k - 'a' >= 0 && k - 'a' <= 25){
                key[k - 'a'] = 1;
            }
        }

        queue<pair<int, int> >Q;
        // for(int r : {0, h-1}){ /*출발할 수 있는 지점을 설정해준다*/
        //     for(int c=0;c<w;c++){
        //         if(board[r][c] == '.'){
        //             vis[r][c] = 1;
        //             Q.push({r, c});
        //         }else if(board[r][c] - 'A' >= 0 && board[r][c] - 'A' <= 25){
        //             if(key[board[r][c] - 'A'] == 1) {
        //                 vis[r][c] = 1;
        //                 Q.push({r, c});
        //             }
        //         }else if(board[r][c] - 'a' >= 0 && board[r][c] - 'a' <= 25){
        //             vis[r][c] = 1;
        //             Q.push({r, c});
        //             key[board[r][c] - 'a'] = 1;
        //         }else if(board[r][c] == '$'){
        //             ans++;
        //             vis[r][c] = 1;
        //             Q.push({r, c});
        //         }
        //     }
        // }
        // for(int r=1;r<h-1;r++){ /*출발할 수 있는 지점을 설정해준다*/
        //     for(int c : {0, w-1}){
        //         if(board[r][c] == '.'){
        //             vis[r][c] = 1;
        //             Q.push({r, c});
        //         }else if(board[r][c] - 'A' >= 0 && board[r][c] - 'A' <= 25){ //대문자인 경우
        //             if(key[board[r][c] - 'A'] == 1) {
        //                 vis[r][c] = 1;
        //                 Q.push({r, c});
        //             }
        //         }else if(board[r][c] - 'a' >= 0 && board[r][c] - 'a' <= 25){ //소문자인 경우
        //             vis[r][c] = 1;
        //             Q.push({r, c});
        //             key[board[r][c] - 'a'] = 1;
        //         }else if(board[r][c] == '$'){
        //             ans++;
        //             vis[r][c] = 1;
        //             Q.push({r, c});
        //         }
        //     }
        // }

        // vector<pair<int, int> > letter;
        queue<pair<int, int> >d[26];
        vis[0][0] = 1;
        Q.push({0, 0});
        while(!Q.empty()){
            int x, y;
            tie(x, y) = Q.front(); Q.pop();
            for(int dir=0;dir<4;dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || ny < 0 || nx > h+1 || ny > w+1) continue;
                if(board[nx][ny] == '*' || vis[nx][ny] > 0) continue;
                if(board[nx][ny] - 'a' >= 0 && board[nx][ny] - 'a' <= 25){ //알파벳 소문자인 경우
                    key[board[nx][ny] - 'a'] = 1;
                    while(!d[board[nx][ny]-'a'].empty()){
                        int tx, ty;
                        tie(tx, ty) = d[board[nx][ny]-'a'].front(); d[board[nx][ny]-'a'].pop();
                        Q.push({tx, ty});
                    }
                    // queue<int>e;
                    // for(int idx=0;idx<letter.size();idx++){
                    //     int tx, ty;
                    //     tie(tx, ty) = letter[idx];
                    //     if(vis[tx][ty] > 0){
                    //         // letter.erase(letter.begin() + idx);
                    //         e.push(idx);
                    //         continue;
                    //     }
                    //     if(key[board[tx][ty] - 'A'] > 0){
                    //         vis[tx][ty] = 1;
                    //         Q.push({tx, ty});
                    //         e.push(idx);
                    //         // letter.erase(letter.begin() + idx);
                    //     }
                    // }
                    // while(!e.empty()){
                    //     int t = e.front(); e.pop();
                    //     letter.erase(letter.begin() + t);
                    // }
                }
                if(board[nx][ny] - 'A' >= 0 && board[nx][ny] - 'A' <= 25) { //알파벳 대문자인 경우
                    if(key[board[nx][ny] - 'A'] != 1){
                        // letter.push_back({nx, ny}); 
                        vis[nx][ny] = 1;
                        d[board[nx][ny] - 'A'].push({nx, ny});
                        continue;
                    }
                }
                if(board[nx][ny] == '$') ans++;
                vis[nx][ny] = 1;
                Q.push({nx, ny});
            }
        }
        cout << ans << "\n";
    }
}
/*
구현은 대체적으로 맞았는데, (열쇠가 없던 문들을 저장해 놓고 열쇠를 찾는 순간 그 문들로 순간이동 할 수 있게끔 하는 거)
아니 대체 왜 자꾸 33퍼에서 틀리는걸까...
결국 해석을 봤는데 내 풀이와 해석과 다른 점이 크게 2가지 있었음
1. 처음에 입장할 수 있는 곳을 찾을 때 풀이는 행, 열이 한 개씩 큰 격자를 (0, 0) 부터 서칭하는 방식으로 시작 (애초에 board 크기가 (w+1)*(h+1) 이렇게 시작하고 우선 0으로 채워둠)
나는 그냥 board size는 w*h로 그대로 두고 맨 변두리 4줄 서칭해서 ., $, 알파벳인 경우 각자 따져줌

2. 풀이에서는 열쇠 없는 문 찾았을 때 저장해두려고 길이가 26인 queue<pair<int, int> >d[26] 배열을 만들어서 바로 바로 push, 그래서 열쇠 찾으면 그 배열 인덱스로 가서
empty 할 때까지 다 Q.push 해줌.
나는 알파벳은 따로 구분 안하고 그냥 큰 vector 하나 만들어서 key 찾을 떄마다 vector iterate 해가며 Key update 된거 있는지 찾아봄.
시간은 더 소모될 수도 있지만, 시간 초과로 틀린 게 아니니.. 대체 왜 틀린걸까..
아.. 그리고 vis[x][y] = 1 을 나는 미리 안 해주고 벡터에서 뺄 때 해줬는데 풀이에서는 그냥 미리 해줌.

1, 2번 중 무엇때문에 틀렸는지 모르겠어서 1번만 고쳐서 해보고 2번만 고쳐서 해봤는데 둘 다 33퍼에서 틀림.. 하.. 왜 틀린걸까
우선 지금은 패쓰.
*/