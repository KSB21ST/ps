#include <bits/stdc++.h>
using namespace std;
string board[5];
bool visited[5][5];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int ans = 0;
vector<pair<int, int> >v;
void func(int cnt, int x, int y, int num_s){
    string s = "";
    for(int i=0;i<cnt;i++) s += "_";
    cout << s << "func cnt: " << cnt << " " << x << " " << y << " " << board[x][y] << "\n";
    if(cnt == 7){
        if(num_s < 4) return;
        cout << "\nsuccess!!!!!!!!!\n";
        ans++;
        return;
    }
    int nx = x + 1;
    int ny = y + 1;
    
    for(int dir=0;dir<2;dir++){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
        if(visited[nx][ny]) continue;
        int nnum_s = num_s;
        if(board[nx][ny] == 'S')
            nnum_s++;
        visited[nx][ny] = true;
        func(cnt+1, nx, ny, nnum_s);
        visited[nx][ny] = false;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0;i<5;i++) cin >> board[i];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            visited[i][j] = true;
            if(board[i][j] == 'S')
                func(1, i, j, 1);
            else
                func(1, i, j, 0);
            visited[i][j] = false;
        }
    }
    cout << ans;
}