#include <bits/stdc++.h>
using namespace std;
/*
p가 작은 숫자여서 가능했던 노가다, 그러나 장렬하게 시간초과 남.
코드 짜면서도 이건 아닌데.. 라고 느낌..

char board[1001][1001];
char vis[1001][1001];
int s[10];
int jump[10];
int n, m, p;
int cnt = 0;
int castle(queue<pair<int, int> > &Q, int i){
    // cout << "in castle " << i << "\n";
    if(Q.empty()){
        return 1;
    }
    // cout << "jump: " << jump[i-1] << "\n";
    int limit = Q.size();
    while(limit--){
        int x, y;
        tie(x, y) = Q.front();
        // cout << "x, y: " << x << " " << y << "\n";
        cnt++;
        s[i-1]++;
        for(int dir=1;dir<=jump[i-1];dir++){
            int nx = x + dir;
            int ny = y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == '#' || vis[nx][ny] > 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            // cout << "push1: " << nx << " " << ny << "\n";
        }
        for(int dir=1;dir<=jump[i-1];dir++){
            int nx = x - dir;
            int ny = y;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == '#' || vis[nx][ny] > 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            // cout << "push2: " << nx << " " << ny << "\n";
        }
        for(int dir=1;dir<=jump[i-1];dir++){
            int nx = x;
            int ny = y + dir;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == '#' || vis[nx][ny] > 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            // cout << "push3: " << nx << " " << ny << "\n";
        }
        for(int dir=1;dir<=jump[i-1];dir++){
            int nx = x;
            int ny = y - dir;
            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if(board[nx][ny] == '#' || vis[nx][ny] > 0) continue;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
            // cout << "push4: " << nx << " " << ny << "\n";
        }
        Q.pop();
        // cout << "poped: " << x << " " << y << "\n";
    }
    // cout << "after: i: " << i << " size: " << Q.size() << "\n";
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    queue<pair<int, int> >Q1;
    queue<pair<int, int> >Q2;
    queue<pair<int, int> >Q3;
    queue<pair<int, int> >Q4;
    queue<pair<int, int> >Q5;
    queue<pair<int, int> >Q6;
    queue<pair<int, int> >Q7;
    queue<pair<int, int> >Q8;
    queue<pair<int, int> >Q9;
    for(int i=0;i<p;i++){
        cin >> jump[i];
        int k = max(n, m);
        if(jump[i] > k) jump[i] = k;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == '1'){
                vis[i][j] = 1;
                Q1.push({i, j});
            }else if(board[i][j] == '2'){
                vis[i][j] = 1;
                Q2.push({i, j});
            }else if(board[i][j] == '3'){
                vis[i][j] = 1;
                Q3.push({i, j});
            }
            else if(board[i][j] == '4'){
                vis[i][j] = 1;
                Q4.push({i, j});
            }
            else if(board[i][j] == '5'){
                vis[i][j] = 1;
                Q5.push({i, j});
            }else if(board[i][j] == '6'){
                vis[i][j] = 1;
                Q6.push({i, j});
            }
            else if(board[i][j] == '7'){
                vis[i][j] = 1;
                Q7.push({i, j});
            }else if(board[i][j] == '8'){
                vis[i][j] = 1;
                Q8.push({i, j});
            }else if(board[i][j] == '9'){
                vis[i][j] = 1;
                Q9.push({i, j});
            }else if(board[i][j] == '#'){
                cnt++;
            }
        }
    }

    while(cnt < n*m){
        int i1 = castle(Q1, 1);
        int i2 = castle(Q2, 2);
        int i3 = castle(Q3, 3);
        int i4 = castle(Q4, 4);
        int i5 = castle(Q5, 5);
        int i6 = castle(Q6, 6);
        int i7 = castle(Q7, 7);
        int i8 = castle(Q8, 8);
        int i9 = castle(Q9, 9);
        if(i1 && i2 && i3 && i4 && i5 && i6 && i7 && i8 && i9)
            break;
    }

    for(int i=0;i<p;i++){
        cout << s[i] << " ";
    }
}
*/

/*
char board[1001][1001];
char vis[1001][1001];
int cnt[10];
int jump[10];
int n, m, p;
queue<tuple<int, int, int> >Q[10];
queue<tuple<int, int, int> >Q2[10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    for(int i=0;i<p;i++){
        cin >> jump[i];
        int k = max(n, m);
        jump[i] = min(k, jump[i]);
    }
    fill(cnt, cnt + 10, 0);
    for(int i=0;i<n;i++) fill(vis[i], vis[i] + m, 0);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] != '#' && board[i][j] != '.'){
                int temp = board[i][j] - '0';
                vis[i][j] = 1;
                Q[temp-1].push({i, j, jump[temp-1]});
            }
        }
    }
    int c = 0;
    int turn = 1;
    int empty = 0;
    while(1){
        // cout << "current player: " << c << "\n";
        if(empty >=p){
            break;
        }
        if(turn){
            // cout << "turn is 1\n";
            if(Q[c].empty()){
                empty++;
                continue;
            }
            while(!Q[c].empty()){
                int x, y, j;
                tie(x, y, j) = Q[c].front(); Q[c].pop();
                // cout << "poped1: " << x << " " << y << "\n";
                cnt[c]++;
                vector<pair<int, int> >v;
                for(int dir=1;dir<=j;dir++){
                    v.push_back({x+dir, y});
                    v.push_back({x-dir, y});
                    v.push_back({x, y+dir});
                    v.push_back({x, y-dir});
                }
                for(auto k:v){
                    int nx, ny;
                    tie(nx, ny) = k;
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(board[nx][ny] == '#' || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q2[c].push({nx, ny, j});
                    // cout << "pushed1: " << nx << " " << ny << "\n";
                }
            }
            c++;
            c = c % p;
            if(c == 0)
                turn = 1 - turn;
            continue;
        }else{
            // cout << "turn is 0\n";
            if(Q2[c].empty()){
                empty++;
                continue;
            }
            while(!Q2[c].empty()){
                int x, y, j;
                tie(x, y, j) = Q2[c].front(); Q2[c].pop();
                // cout << "poped2: " << x << " " << y << "\n";
                cnt[c]++;
                vector<pair<int, int> >v;
                for(int dir=1;dir<=j;dir++){
                    v.push_back({x+dir, y});
                    v.push_back({x-dir, y});
                    v.push_back({x, y+dir});
                    v.push_back({x, y-dir});
                }
                for(auto k:v){
                    int nx, ny;
                    tie(nx, ny) = k;
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(board[nx][ny] == '#' || vis[nx][ny] == 1) continue;
                    vis[nx][ny] = 1;
                    Q[c].push({nx, ny, j});
                    // cout << "pushed2: " << nx << " " << ny << "\n";
                }
            }
            c++;
            c = c % p;
            if(c == 0)
                turn = 1 - turn;
        }
    }
    for(int i=0;i<p;i++){
        cout << cnt[i] << " ";
    }

}
*/
/*
위에 코드: 두 가지 문제점이 존재했다: 자꾸 시간초과 나고, 또 예제입력 5에서 자꾸 13 3 이 나왔다.
문제를 잘못 이해하고 있었다. 왼쪽, 오른쪽, 위쪽, 아래쪽 그냥 직진만 가능한 줄 알았다. 알고보니 ㄱ, ㄴ 자로 꺾어도 되었던 문제였다.
일단 그래서 틀렸고,
푸는 방법 구상은 큰 그림에서 맞았던 것 같은데 (각 player마다 queue를 만들고 돌리는 거)
1. step 이 2 이상일 때 해당하는 칸들을 도는 게 너무 노가다로 짜서 문제였고 (그리고 직선 거리만 고려했다)
2. 새로 영역을 확장할 때 추가된 애들을 queue에 넣어주는데 이 [새로운 뉴비]들을 [기존에 확장을 해야되는데 아직 안 한 애들]하고 큐 안에서 섞이는 걸 잘 분류해주지 못했다.
바킹독 풀이를 보았는데
-> queue로 된 array를 만드는 새로운 기법을 배웠고
-> nextq를 설정해주어 새로온 뉴비들을 nextq에 따로 저장을 해두었다가 iteration이 끝난 후에야 뉴비들을 기존의 queue에 넣어주었다
-> 기존 확장을 해야 하는 칸으로부터 뉴비의 거리를 queue 안에 같이 tuple로 저장해두었다. --> step 이하의 칸들의 iteration을 관리해주었다
근데 그래도 첫 번째 풀이랑 얼추 알고리즘과 복잡도는 비슷한 것 같은데 왜 첫 번쨰는 시간초과가 났는지 모르겠다 메모리 초과도 아니고 시간 초과... 같은 O(NM) 인 것 같은데.
*/
char board[1001][1001];
int vis[1001][1001];
int jump[10];
int cnt[10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<tuple<int, int, int> >Q[10];
int n, m, p;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> p;
    for(int i=1;i<=p;i++) cin >> jump[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> board[i][j];
            if(board[i][j] == '#'){
                vis[i][j] = 1;
            }else if(board[i][j] == '.'){
                vis[i][j] = 0;
            }else{
                int temp = board[i][j] - '0';
                vis[i][j] = 1;
                Q[temp].push({i, j, 0});
            }
        }
    }

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout << vis[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    while(1){
        int isExtended = 0; //만약 그 어떤 queue도 extended 되지 않았다면 판을 다 돌았다는 뜻이므로 loop을 끝내줘야한다.
        for(int i=1;i<=p;i++){ //i 는 현재 player 번호를 나타낸다
            queue<tuple<int, int, int> >nextq;
            while(!Q[i].empty()){
                int x, y, step;
                tie(x, y, step) = Q[i].front(); Q[i].pop();
                if(step >= jump[i]){ //만약 2칸이 최대 step이라면, 1칸 거리 칸들을 돌면서 그 칸들을 확장해야 하기 때문에 거리가 2칸인 애들은 다음 차례에 돌아야 한다
                    nextq.push({x, y, 0}); //step을 초기화시켜준다음 다음에 돌 nextq로 보내준다.
                    continue;
                }
                cnt[i]++;
                for(int dir=0;dir<4;dir++){
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    if(vis[nx][ny] > 0) continue;
                    vis[nx][ny] = 1;
                    Q[i].push({nx, ny, step + 1});
                    isExtended = 1;
                }
            }
            Q[i] = nextq; //queue를 이렇게 = 으로 해줄 수 있다는 거 처음 알았다
        }
        if(!isExtended)
            break;
    }
    for(int i=1;i<=p;i++){
        cout << cnt[i] << " ";
    }
}